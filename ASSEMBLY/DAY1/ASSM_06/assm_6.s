    AREA mycode6, CODE, READONLY
    ENTRY  
	EXPORT start

start
        LDR R0, =num1         ; Load the address of num1 into R0
        LDR R0, [R0]          ; Load the value of num1 into R0

        LDR R1, =num2         ; Load the address of num2 into R1
        LDR R1, [R1]          ; Load the value of num2 into R1

        ADD R2, R0, R1        ; Add the values of R0 and R1 and store the result in R2

        LDR R3, =result       ; Load the address of the result location into R3
        STR R2, [R3]          ; Store the result in memory (at address stored in R3)

        ; Push R2 onto the stack (to simulate storing the result on the stack)
        PUSH {R2}             ; Push R2 onto the stack

        ; Pop the result from the stack into R4
        POP {R4}              ; Pop the value into R4

        B .
		
num1    DCD 10      ; First number (32-bit)
num2    DCD 20      ; Second number (32-bit)
result  DCD 0       ; Result of addition (32-bit)
        
        END
