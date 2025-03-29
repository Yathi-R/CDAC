#include<stdio.h>
#include "fact.c"

int main(){

int n;
printf("Enter a number: \n");
scanf("%d",&n);
 if(n == 0 || n==1){
  printf("factorial of %d is 1", n);
 }
 else if(n>1){
  long double factorial = fact(n);
  printf("factorial of %d is %Lf\n", n, factorial);
 }
 else{
 printf("Enter value is negative");
 }
}
