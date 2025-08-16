/*To find type of triangle*/

#include<stdio.h>

int main(){
    int side1, angle1, angle2, angle3, n, side2, side3;

    printf("Enter 0 for side and 1 for angle: ");
    scanf("%d", &n);

    switch(n){
        case 0: printf("Enter the length of 3 sides: ");
                scanf("%d%d%d", &side1, &side2, &side3);

                /*Checks if triangle is valid*/
                if((side1 <=0 || side2 <=0 || side3 <= 0) || (side1+side2<=side3 || side1+side3<=side2 || side2+side3<=side1)){
                    printf("Invalid triangle\n");
                }

                /*below condition checks for type of triangle based on sides*/
                else if (side1 == side2 && side1 == side3){
                    printf("It's equilateral triangle\n");
                }

                else if (side1 == side2 || side1 == side3 || side2 == side3 ){
                    printf("It's Isosceles triangle\n");
                }
                else{
                    printf("It's Scalene triangle\n");
                }
                break;
    
        case 1: printf("Enter the 3 angles in between 0 to 180: ");
                scanf("%d%d%d", &angle1, &angle2, &angle3);

                /*Checks if triangle is valid*/
                if((angle1+angle2+angle3!=180) || (angle1 <= 0 || angle2 <= 0 || angle3 <= 0 || angle1==180 || angle2 == 180 ||angle3 == 180)){
                    printf("Invalid triangle\n");
                }
                   
                /*below condition checks for type of triangle based on angles*/
                else if(angle1 <90 && angle2 <90 && angle3 < 90){
                    printf("It's acute triangle\n");
                }
                else if(angle1 ==90 || angle2 == 90 || angle3 ==90){
                    printf("It's Right angle Triangle\n");
                }
                else {
                    printf("It's Obtuse Triangle\n");
                }
                break;
    
        default: printf("Invalid choice");
                break;
    }

    
return 0;
}