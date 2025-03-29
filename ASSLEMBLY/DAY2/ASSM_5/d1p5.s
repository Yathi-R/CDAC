	AREA MYCODE4, CODE, READONLY
	ENTRY
	EXPORT start 
	EXPORT rever_store
	EXPORT rev_hex_nibbles
	
start PROC
    
	LDR R0, =NUM1
	BL rever_store
	
	LSL R1,R3, #24
	LSL R2, R4, #16
	
	ORR R1, R1, R2

	LSL R2,R5, #8
		
	ORR R2, R2, R6
		
	B .
	ENDP

rever_store PROC
	
	PUSH {LR}
	
	LDRB R3, [R0]
	LDRB R4, [R0, #1]
	LDRB R5, [R0, #2]
	
	BL rev_hex_nibbles
	
	MOV R6, R5
		
	LDRB R5, [R0, #3]
	
	BL rev_hex_nibbles
	
	MOV R7, R5
	
	POP{LR}
	BX LR
	ENDP

rev_hex_nibbles PROC

	AND R7, R5, #0x0F
	LSL R7, #4
	
	AND R8, R5, #0xF0
	LSR R8, #4

	ORR R5, R7, R8
	
	BX LR
	ENDP
		
NUM1 DCD 0x12345678

	END