/*To perform basic calc using individual function*/

#include<stdio.h>
#include<math.h>

int getnum();
void display(float);
int addfun(int, int);
int subfun(int, int);
int mulfun(int, int);
float divfun(int, int);

int main(){
    int num1 = getnum();
    int num2 = getnum();

    float result;
    
    result = addfun(num1, num2);
    display(result);

    result = subfun(num1, num2);
    display(result);

    result = mulfun(num1, num2);
    display(result);

    result = divfun(num1, num2);
    display(result);

return 0;
}

int getnum(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}
void display(float result){

    if (isnan(result)){

        printf("Invalid operation: can't divide by 0.\n");
    }
    else {

        printf("Result: %0.2f\n", result);
    }
}
int addfun(int a, int b){

     return a + b;
}
int subfun(int a, int b){
    
    return a-b;
}
int mulfun(int a, int b){
    
    return a*b;
}
float divfun(int a, int b){
    
    if(b != 0){
        
        return (float)a/b;
    }
    else {
        
        return NAN;
    }
   
}