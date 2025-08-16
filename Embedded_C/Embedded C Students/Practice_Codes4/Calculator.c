#include<stdio.h>
#include<stdlib.h>

// Basic calculator
typedef enum menu{
    EXIT, ADD, SUB, MUL, DIV
}menu_t;

menu_t menu_list(void);
float add(float, float);
float sub(float, float);
float mul(float, float);
float divison(float, float);
float accept_number(void);
void print_result(float result);


int main(void)
{
    menu_t choice;
    float n1, n2, result;

    while((choice = menu_list()) != 0)
    {
        n1 = accept_number();
        n2 = accept_number();
        switch(choice)
        {
            case EXIT:
                exit(0);
                break;
            case ADD:
                result = add(n1, n2);               
                break;

            case SUB:
                result = sub(n1, n2);
                break;

            case MUL:
                result = mul(n1, n2);
                break;

            case DIV:
                result = divison(n1, n2);
                break;
        }
        print_result(result);
    }
   
    return 0;
}

float accept_number(void)
{
    float num;

    printf("Enter float number: ");
    scanf("%f", &num);
    return num;
}

void print_result(float result)
{
    printf("result = %f\n", result);
}

menu_t menu_list(void)
{
    menu_t ch;
    printf("0. EXit\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    return ch;
}

float add(float num1, float num2)
{
    float res = num1 + num2;
    return res;
}

float sub(float num1, float num2)
{
    return num1 - num2;
}

float mul(float num1, float num2)
{
    return num1 * num2;
}

float divison(float num1, float  num2)
{
    return num1 / num2;
}

