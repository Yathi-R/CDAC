#include<stdio.h>

int main(void)
{
    short num3;
    int num1, num2;
    char ch;
    int res;
    
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    res = num1 + num2;
        // int + int
    printf("num1 = %d, num2 = %d, res = %d\n", num1, num2, res);
    
   
    printf("Enter two number : ");
    scanf("%d %hd", &num1, &num3);

    res = num1 + num3;
        //int + short(int)
    printf("num1 = %d, num3 = %hd, res = %d\n", num1, num3, res);
    

    num1 = 100;
    ch = 'A';
    res = num1 + ch;
        //int + char(int)
    printf("res = %d\n", res);

  
    return 0;
}