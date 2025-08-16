#include<stdio.h>

static int globalVar = 0;
			void function() {
    			globalVar++;
    			printf("%d\n", globalVar);
			}

int main()
{
    globalVar++;
    function();
    function();
    function();

}
