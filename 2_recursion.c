#include <stdio.h>
#include <math.h>

int factorial(int num);

void main(void){
    
    int input = 7;
    
    
    int output = factorial(input);
    
    printf("Input: %d\n",input);
    printf("Output: %d\n",output);
    
    return;
}

int factorial(int num)
{
    //factorial function
    if(num == 1)
        return num;
    else
        return num * factorial(num-1);
}