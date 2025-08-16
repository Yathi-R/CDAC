/*Write a function that takes a Color and returns a string representing the color. Print the color in
main based on the favoriteColor value.*/

#include<stdio.h>
#include <string.h>

//Type defining enum as colours
typedef enum {
    RED,
    GREEN,
    YELLOW,
    BLACK,
    WHITE,
    BROWN,
    BLUE,
    LIGHT_BLUE,
    LIGHT_GREEN,
    VIOLET,
    INDICA
}colours;

//Function taking color and returning a string
char *getFavColor(colours color){

    switch (color) {
        case RED:
            return "A color of passion and energy";
        case GREEN:
            return "A color of nature and growth";    
        case YELLOW:
            return "A bright, cheerful color of sunshine";
        case BLACK:
            return "A color of elegance and mystery";
        case WHITE:
            return "A color of purity and simplicity";
        case BROWN:
            return "A color of earth and stability";
        case BLUE:
            return "A calming color of the sky and sea";
        case LIGHT_BLUE: 
            return "A soft and serene shade of blue";
        case LIGHT_GREEN: 
            return "A fresh, light shade of green";
        case VIOLET: 
            return "A color of creativity and imagination";
        case INDICA: 
            return "A deep, rich purple color";
        default:
            return "Unknown Color";
    }
}

int main(){

    int favcolor;
    char desc[50];

    printf("Enter your favourite colour:\n\
[0-RED, 1-GREEN, 2-YELLOW, 3-Black, 4-White, 5-Brown,\
6-Blue, 7-LIGHT_BLUE, 8-LIGHT_GREEN, 9-VIOLET, 10-INDICA]: ");

    scanf("%d", &favcolor);

    //Fun call to get string corresponding to color
    strcpy(desc, getFavColor(favcolor));

    printf("Desc of the colour is: %s\n", desc);

    return 0;
}