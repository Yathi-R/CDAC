    AREA MYCODE2, CODE, READONLY
    ENTRY
    EXPORT start
		
LABEL_ADDR EQU 0x20000100

start PROC
    
    LDR     R0, =LABEL_ADDR
	LDR     R1, =0x20000600
	
	MOV32	R3, #0x12345678
	MOV32 	R2, #0xFFFF00FF
	MOVW	R7, #0xFFFF
	
	STR		R3, [R0], #4
	STR		R2, [R0], #4
	STR 	R7, [R0], #2
		
    MOV     R4, #10
    MOV     R5, #0
	
	LDR     R0, =LABEL_ADDR

add_bytes_loop
    LDRB    R6, [R0], #1
    ADCS    R5, R6, R5
    SUBS    R4, R4, #1
    BNE     add_bytes_loop

    STR     R6, [R1]

    B .
	ENDP

	END
