    AREA    MYCODE3, CODE, READONLY
    ENTRY   
    EXPORT  start

start PROC
    
    LDR     R0, =0x20000100     ; R0 = source address (0x20000100)
    LDR     R1, =0x20000200     ; R1 = destination address (0x20000200)
	
	; Store 4 words (16 bytes) at 0x20000100
    LDR     R2, =0x11111111     ; First word value
    STR     R2, [R0]            ; Store at 0x20000100
    LDR     R2, =0x22222222     ; Second word value
    STR     R2, [R0, #4]        ; Store at 0x20000104
    LDR     R2, =0x33333333     ; Third word value
    STR     R2, [R0, #8]        ; Store at 0x20000108
    LDR     R2, =0x44444444     ; Fourth word value
    STR     R2, [R0, #12]       ; Store at 0x2000010C
    
    ; Perform block transfer of 16 bytes
    LDMIA   R0!, {R2-R5}        ; Load 4 words (16 bytes) from R0 to R2-R5
    STMIA   R1!, {R2-R5}        ; Store 4 words (16 bytes) from R2-R5 to R1
    
stop B stop
	
	ENDP
		
    END