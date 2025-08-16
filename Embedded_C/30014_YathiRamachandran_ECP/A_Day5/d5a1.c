/*Take number and character from user and print character that number of times using
while loop.*/

/* take a number and char and print char that no of times using while loop*/

#include<stdio.h>

// function prototype
void loopfun(int *, char *);
int getnum();
char get_char();

int main(){

    int num = getnum(); //function calling to get a number
    
    char ch = get_char(); //fun calling to get a char

    loopfun(&num, &ch); //fun calling by passing argu by reference to display char of num times

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

//fun to display char of n times 
void loopfun(int *num, char *ch){

    printf("Displaying char \" %c \" of %d times: \n", *ch, *num); //dereferencing ch and num

    int temp = *num; //assigning temp with num by dereferencing num

    //while loop to print char by n times
    while( temp > 0 ){
        printf("%c\n", *ch);
        temp--;
    }

    
}