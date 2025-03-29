	AREA MYCODE,CODE,READONLY
	ENTRY
	EXPORT start
	EXPORT msp_push
	EXPORT psp_push

start PROC
    
	BL msp_push
	
	BL psp_push

    B .
	ENDP

msp_push PROC
    
    MOV     R0, #0x1
    MOV     R1, #0x2
    MOV     R2, #0x3
    MOV     R3, #0x4
    MOV     R4, #0x5
    MOV     R5, #0x6
    
    ;LDR     R6, =0x20004000
    MRS     R6, MSP
	
    
    PUSH    {R0-R5, LR}
	PUSH	{R6}
	POP		{R6}
    POP     {R7-R12, LR}
    
	MSR		MSP, R6
	
    BX      LR
	ENDP

psp_push PROC
    
    MOV     R0, #0x1
    MOV     R1, #0x2
    MOV     R2, #0x3
    MOV     R3, #0x4
    MOV     R4, #0x5
    MOV     R5, #0x6
    
    LDR     R6, =0x20002000
    MSR     PSP, R6
	
	MSR		CONTROL, R2
    
    PUSH    {R0-R5, LR}
	PUSH	{R6}

	POP		{R6}
    POP     {R7-R12, LR}
    
    BX      LR
	ENDP

	END
