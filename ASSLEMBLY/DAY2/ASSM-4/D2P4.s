	AREA MYCODE4, CODE, READONLY
	ENTRY
	EXPORT start
	EXPORT to_uppercase
		
start PROC
    
	MOV32 	R2, #0x20000400
    LDR     R0, =string
    BL      to_uppercase
	
    
	B .
	ENDP 
		
to_uppercase PROC
    
next_char
        LDRB    R1, [R0], #1
        CMP     R1, #0
        BEQ     done
        
        CMP     R1, #'a'
        BLT     store_otherkeys
        CMP     R1, #'z'
        BGT     store_otherkeys
        
        SUB     R1, R1, #32
        STRB    R1, [R2], #1
        
        B       next_char
		
store_otherkeys STRB    R1, [R2], #1
				B next_char
        
done	BX LR
		ENDP
    
string DCB "this is a test", 0

	END