    AREA MYCODE,CODE,READONLY
	ENTRY
	EXPORT start

start PROC

  
    LDR     R0, =num1   
    LDR     R0, [R0]    
    LDR     R1, =num2   
    LDR     R1, [R1]    

    
    ADD     R2, R0, R1  
    LDR     R3, =result_add 
    STR     R4, [R3]        

    
    SUB     R2, R0, R1      
    LDR     R3, =result_sub 
    STR     R4, [R3]        

    
    MUL     R2, R0, R1      
    LDR     R3, =result_mul 
    STR     R4, [R3]        

    
    CMP     R1, #0          
    BEQ     div_by_zero     

    
    SDIV    R2, R0, R1      
    LDR     R3, =result_div 
    STR     R4, [R3]        
    B       done            

div_by_zero
    MOV     R2, #0          
    LDR     R3, =result_div 
    STR     R2, [R3]        

done
    B .           
	ENDP

	AREA  MYCODEDATA,CODE,READONLY
	
num1 		DCD		10   
num2  		DCD		5    
result_add  DCD		0    
result_sub  DCD		0    
result_mul  DCD		0    
result_div	DCD		0    
	
	
	END