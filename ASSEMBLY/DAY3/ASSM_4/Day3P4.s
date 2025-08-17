    AREA    MYCODE4, CODE, READONLY
    ENTRY
    EXPORT  start

start   PROC
    ; Initially in Thread mode, privileged, using MSP
    ; Switch to PSP as stack pointer
    MRS     R0, CONTROL         ; Read CONTROL register
    ORR     R0, R0, #0x02       ; Set bit 1 (SPSEL) to use PSP
    MSR     CONTROL, R0
    
    LDR     R0, =0x20004000
    MSR     PSP, R0
    
    ; Switch to unprivileged access level in Thread mode
    MRS     R0, CONTROL
    ORR     R0, R0, #0x01       ; Set bit 0 for unprivileged
    MSR     CONTROL, R0
    
    SVC     #0x05                  ; Call SVC with number 5
    
stop B stop
    
    ENDP

    AREA    SVCHANDLER, CODE, READONLY
    EXPORT  SVC_Handler

SVC_Handler PROC
    ; On entry, R0-R3, R12, LR, stacked PC and PSR are stacked
    ; Exception number is in the stacked PC
    
    ; Get the stacked PC (return address) to extract SVC number
    MRS     R0, PSP             ; Get current PSP
    LDR     R1, [R0, #24]       ; Load stacked PC (offset 6 words = 24 bytes)
    SUB     R1, R1, #2          ; Adjust PC to point to SVC instruction as PC points to ext instruction
    LDRB    R0, [R1]            ; Load the SVC instruction (lower byte)
   ; AND     R0, R0, #0xFF       ; Mask to get SVC number (5)
    
    ; R0 now contains the SVC number
    
    ; Disable all hardware interrupts
    CPSID   I                   ; Clear PRIMASK, disable interrupts
    
    ; Re-enable privileged access in Thread mode
    MRS     R1, CONTROL         ; Read CONTROL register
    BIC     R1, R1, #0x01       ; Clear bit 0 (nPRIV) for privileged mode
    MSR     CONTROL, R1
    
    ; Return from exception
    BX      LR                  ; Return to Thread mode
    
    ENDP

    END