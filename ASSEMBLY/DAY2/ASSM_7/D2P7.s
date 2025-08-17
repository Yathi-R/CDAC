	AREA MYCODE7, CODE, READONLY
	ENTRY
	EXPORT start

start PROC
	MOV32 R0, #0x20000000
	MOV R1, #0x00
	
	STR R1,[R0]
	LDR R2,[R0]
	
    ORR     R1, R1, #0x80
    STR     R1, [R0]          
                        
    B .             
    ENDP
    END		
		
	
	