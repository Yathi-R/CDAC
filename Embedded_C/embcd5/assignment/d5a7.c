/*Write a C program to reads a string from the user, use pointers to reverse the string in
place and prints the original and reversed strings.*/

 #include<stdio.h>
 #include<string.h>

 //Function to read the string from user
void readinput(char *str, int size){

    //reading string from ther user
    printf("Enter a string: ");
    fgets(str, size, stdin);

    unsigned int len = strlen(str);

    //null termination
    if( len > 0 && str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
}

//function to reverse the string
void reversstring(char *str){

    char *left = str;
    char *right = str + strlen(str) -1;

    while (left < right){

        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

//Function to display the string
void displaystring(const char *str, const char *message){
    printf("%s: %s\n", message, str);
}


 int main(){

    char str[100];
    readinput(str, 100); // Fun call to read string
    displaystring(str, "Original string"); // Fun call to diplay original string 

    reversstring(str); // Fun call to reverse the string
    displaystring(str, "Reversed string"); // fun call to display reversed string

    return 0;

 }