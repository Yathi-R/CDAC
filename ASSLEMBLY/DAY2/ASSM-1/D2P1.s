	AREA MYCODE1, CODE, READONLY
	ENTRY
	EXPORT start
	EXPORT add_unsigned
	EXPORT 	sub_unsigned
		
start PROC
	MOV32 R0, #500
	MOV32 R1, #100
	
	BL add_unsigned
	
	BL sub_unsigned
	
	B .
	
	ENDP
	
add_unsigned PROC
	ADDS R3, R0, R1
	ADC R4, #0
	BX LR
	ENDP

sub_unsigned PROC
	SUBS R5, R0, R1
	BX LR
	ENDP   

	END