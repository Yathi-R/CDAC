    AREA    MYDATA, DATA, READWRITE, align=4
flag_fault  DCD 0x01              ; data section
	
	AREA    MYCODE4, CODE, READONLY
    ENTRY
    EXPORT  start
	EXPORT	SVC_Handler


start   PROC
	
	;Initializing PSP with address
	LDR     R0, =0x20004000
    MSR     PSP, R0
	
    ; Initially in Thread mode, privileged, using MSP
    ; Switch to PSP as stack pointer with unprivileged access
    MRS     R0, CONTROL         ; Read CONTROL register
    ORR     R0, R0, #0x03       ; Set bit 0 & 1 to change to PSP & unprivileged
    MSR     CONTROL, R0
        
        
    SVC     #0x01                  ; Call SVC with number 1 to change from unprivileged to privileged
	SVC     #0x02                  ; Call SVC with number 2 to change from PSP to MSP
	
	; Here it was observed that we were unable to change from PSP to MSP after returning from SVC handler 
	; even though we modified CONTROL register in SVC.
	; This was because, once returning from SVC, unstacking updates the CONTROL register in Thread Mode to it's previous state
	; i.e PSP
	
	; This behaviour was discussed with professor and he affirmed the same and Instructed to change SP Mode in Thread Mode itself
	
	MRS     R0, CONTROL         ; Read CONTROL register
    BIC     R0, R0, #0x02       ; Clears bit 1 to change from PSP to MSP
    MSR     CONTROL, R0			; Chnages to MSP
	
	SVC     #0x03                  ; Call SVC with number 3 to disable all interrupts and write SVC number to R0
	
	LDR		R3, =flag_fault
	MOV		R4, #0x01
	STR 	R4, [R3]				;Setting fault flag to R3 manually
	
	LDR	R4, [R3]
	CMP		R4, #0x01 
	BNE		no_fault				; checking if fault flag is set manually using a preset variable
	
	SVC     #0x04                  ; Call SVC with number 4 to clear flag

no_fault

stop B stop
    
    ENDP
		
    AREA    SVCHANDLER, CODE, READONLY
    EXPORT  SVC_Handler

SVC_Handler PROC
	
    ; On entry, R0-R3, R12, LR, stacked PC and PSR are stacked
    ; Exception number is in the stacked PC
    
    ; Get the stacked PC (return address) to extract SVC number
	TST		LR, #4
	ITE		EQ
	MRSEQ	R0, MSP				; Get current MSP
    MRSNE   R0, PSP             ; Get current PSP
    LDR     R1, [R0, #24]       ; Load stacked PC (offset 6 words = 24 bytes)
    SUB     R1, R1, #2          ; Adjust PC to point to SVC instruction as PC points to ext instruction
    LDRB    R2, [R1]            ; Load the SVC instruction (lower byte)
      
    ; R0 now contains the SVC number
	
	;Load svc table's base address
	LDR		R3, =svc_table
	LDR		R3, [R3, R2, LSL #2] ; Load svc branch address present in the svc table based on SVC number
	BX		R3					 
	
	ALIGN 4
svc_table
	DCD svc_default		; empty
	DCD svc_case01		; to get privileged access
	DCD svc_case02		; to change from PSP to MSP
	DCD svc_case03		; to diable interrupts and load SVC number
	DCD svc_case04		; To clear all interrupts including hardware fault and clear flag
	
svc_default
	B		svc_exit
	
svc_case01
	; Re-enable privileged access in Thread mode
	MRS     R1, CONTROL         ; Read CONTROL register
    BIC     R1, R1, #0x01       ; Clear bit 0 for privileged mode
    MSR     CONTROL, R1
	B		svc_exit            ; branch to exit
	
svc_case02
	;To try changing from PSP to MSP
	MRS     R1, CONTROL         ; Read CONTROL register
    BIC     R1, R1, #0x02       ; Clear bit 1 for MSP mode
    MSR     CONTROL, R1
	DSB
	ISB
	 
	B		svc_exit
	
svc_case03
   
    ; Disable all hardware interrupts
    CPSID   I                   ; disable interrupts by setting PRIMASK to 1
	MOV		R0, R2				; MOV svc number to R0
	CPSIE	I					; clear PRIMASK
	B		svc_exit
   
svc_case04
	CPSID	I					; Disable all interrupts except hardfault, NMI and RESET
	CPSID	F					; Disables fault exceptions
	LDR		R3, =flag_fault		; Load addrees to R3
	MOV		R4, #0
	STR		R4, [R3]			; Clearing Flag
	
	CPSIE	F					; Enable fault exceptions like HARD Fault
	CPSIE 	I					; Enable all interrupts
	B		svc_exit
	
    
    
svc_exit
    ; Return from exception
    BX      LR                  ; Return to Thread mode
    
    ENDP

    END