#include<stdio.h>



void function() {
    		static int count = 0;  
  		count++;
    		printf("%d\n", count);
		}


int main()
{
    
    function();
    function();
    return 0;
}