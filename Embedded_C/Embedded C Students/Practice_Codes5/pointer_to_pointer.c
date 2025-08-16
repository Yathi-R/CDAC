#include<stdio.h>
/*
    Pointer to pointer - pointer varaiable which is used to store address of pointer varaible
*/


int main(void)
{
    double num = 3.142;
    // num is a double type of variable
    double *pnum = &num;
    // pnum is a variable of double pointer type 

    double **ppnum = &pnum;
    // ppnum is a variable of type double pointer

    printf("num = %lf, &num = %u\n", num, &num);
    printf("pnum = %u, &pnum = %u\n", pnum, &pnum);
    printf("ppnum = %u, &ppnum = %u\n", ppnum, &ppnum);

    *pnum = 5.2;
    printf("num = %lf, *pnum = %lf\n", num, *pnum); 

    **ppnum = 6.3;
    printf("num = %lf, *pnum = %lf, *ppnum = %lf\n", num, *pnum, **ppnum);

    return 0;
}