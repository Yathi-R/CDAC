	AREA MYCODE1, CODE, READONLY
	ENTRY
	EXPORT start
	EXPORT add_signed
	EXPORT 	sub_signed
		
start PROC
	MOV32 R0, #67000
	MOV32 R1, #2147483648
	
	BL add_signed
	
    BMI      store_negative_add      
    B       continue  
    
store_negative_add
    MOV     R4, R2        
	B continue
	
continue        
    BL sub_signed
	       
    BMI      store_negative_sub     
    B       continue_s 
    
store_negative_sub
    MOV     R6, R5       
	B       continue_s

continue_s	
	B .
	
	ENDP
	
add_signed PROC
	ADDS R2, R0, R1
	ADC R3, #0
	BX LR
	ENDP

sub_signed PROC
	SUBS R5, R0, R1
	BX LR
	ENDP
	
	
    END
    


    
