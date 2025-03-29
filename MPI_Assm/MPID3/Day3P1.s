	AREA code1, CODE, READONLY
	ENTRY
	EXPORT start
		
start

	LDR     R0, =0x20001000   
    MSR     MSP, R0
	
	PUSH 
	
	LDR     R0, =0x20002000   // PSP Stack base address (example)
    MSR     PSP, R0
    
    MOV     R0, #0x1
    MOV     R1, #0x2
    MOV     R2, #0x3
    MOV     R3, #0x4
    MOV     R4, #0x5
    MOV     R5, #0x6
        
   
    

    
    PUSH    {R0-R5, R14, LR}
    
    // Pop the values back into R7-R12, R14, PSR
    POP     {R7-R12, R14, PSR}

    // PSP setup (Process Stack Pointer)
               // Set PSP

    // Push R0-R5, R14 (LR), PSR to the stack again
    PUSH    {R0-R5, R14, LR, PSR}
    
    // Pop the values back into R7-R12, R14, PSR
    POP     {R7-R12, R14, PSR}

    // End of program (infinite loop to stop execution)
    B       .

	END