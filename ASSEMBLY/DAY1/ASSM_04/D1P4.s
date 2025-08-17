    AREA MYCODE1, CODE, READONLY
    ENTRY
    EXPORT start
	EXPORT add_subroutine
	EXPORT sub_subroutine
	EXPORT mul_subroutine
	EXPORT div_subroutine

start PROC
    MOV32   R1, #0XFFFFFFFF      
    MOV32   R2, #0XFFFFFFFF      

    MOV32   R3, #0xFFFFFFFF      
    MOV32   R4, #0xFFFFFFFF 

    
    BL add_subroutine

    
    BL sub_subroutine

    
    BL mul_subroutine

    
    BL div_subroutine

    
    B .
	ENDP

add_subroutine PROC
    ADD     R5, R1, R3
    ADCS    R6, R2, R4
    ADC     R7, #0    
    MOV 	PC, LR 
	ENDP
	

sub_subroutine PROC
    SUBS    R5, R1, R3
    SBCS    R6, R2, R4
    MOV 	PC, LR
	ENDP
	

mul_subroutine PROC
    UMULL     R6, R5, R1, R3
    UMULL     R8, R7, R2, R4
    MOV 	PC, LR   
    ENDP	
	

div_subroutine PROC

    MOV     R6, R1  
    UDIV    R5, R6, R3

    
    MOV     R7, R2
    UDIV    R6, R7, R4

    MOV 	PC, LR
	ENDP

	
	END

