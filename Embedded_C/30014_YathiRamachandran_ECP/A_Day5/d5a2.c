/*Take number and character from user and print character that number of times using
recursion.*/

/* take a number and char and print char that no of times using recursion*/

#include<stdio.h>

// function prototype
void loopfun(int *, char *);
int getnum();
char get_char();

int main(){

    int num = getnum(); //function call to get a number
    
    char ch = get_char(); //function call to get a char

    printf("Displaying char \" %c \" of %d times: \n", ch, num);

    loopfun(&num, &ch); //fun call with passing argu by reference to display char 'num' times

return 0;
}

// fun to get a number
int getnum(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}

//fun to get a char
char get_char(){
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    return ch;
}

//recursive fun to display char of n times 
void loopfun(int *num, char *ch){

    // Base case
    if ( *num == 0){
        return;
    }
    else{
        printf("%c\n", *ch);
        
        (*num)--;
        loopfun(num, ch); //recursive fun call
        
    }    
}