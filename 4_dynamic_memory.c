#include <stdlib.h>
#include <stdio.h>

int main(void){
    int num_ele = 4;
    
    int nums[num_ele];
    
    nums[0] = 5;
    
    printf("\n");
    for(int i = 0; i < num_ele; i++){
        nums[i] = i*2;
        printf("Ele %d: %d\n",i,nums[i]);
    }
    
    return 1;
}