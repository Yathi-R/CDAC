#include<stdio.h>
// Take opr1, opr2 and opr from user and perfrom the arithmetic.

int main(void)
{
    int opr1, opr2, res;
    char opr;
    int flag = 0;
    char ch;

    do
    {
        printf("Enter opr1 : ");
        scanf("%d", &opr1);

        printf("Enter Opr : ");
        scanf("%*c%c", &opr);

        printf("Enter opr2 : ");
        scanf("%d", &opr2);

        switch(opr)
        {
            case '+':
                res = opr1 + opr2;
                break;
            case '-':
                res = opr1 - opr2;
                break;
            case '*':
                res = opr1 * opr2;
                break;
            case '/':
                if(opr2 != 0)
                    res = opr1 / opr2;
                else
                {
                    flag = 1;
                    printf("Divide by zero error\n");
                }
                break;
            default:
                printf("Invalid Operator\n");
        }
        if(flag == 0)
            printf("%d %c %d = %d\n", opr1, opr, opr2, res);

        printf("Do you want to continue(y/n) : ");
        scanf("%*c%c", &ch);
        
    }while(ch == 'y');

    return 0;
}