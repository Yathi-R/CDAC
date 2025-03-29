	AREA    mycode5, CODE, READONLY
    ENTRY
    EXPORT  start

start   PROC
      
    LDR     R0, =num1
    LDR     R0, [R0]

    
    LDR     R1, =num2
    LDR     R1, [R1]

    
    ADD     R2, R0, R1
    
    SUB     R3, R0, R1
    
    UMULL    R5, R4, R0, R1
    
    UDIV    R6, R0, R1
  

stop B stop

		ENDP
			
num1    DCD     50
num2    DCD     10

	
		END