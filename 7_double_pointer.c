#include <stdlib.h>
#include <stdio.h>

void change_pointer(int *inp, int **outpp);

void main(){
    int num1 = 5;
    int num2 = 10;
    
    int *num1p = &num1;
    int *num2p = &num2;
    int **numpp = &num1p;
    
    //numpp points to a pointer which points to num1
    printf("num2 = %d before change\n",num2);
    change_pointer(num2p, numpp);
    //numpp points to a pointer which points to num2
    **numpp = 20;
    //now num2 = 20;
    printf("num2 = %d after change\n",num2);

}

void change_pointer(int *inp, int **outpp){
    *outpp = inp;
    
    //without dereferencing, the change wont be seen outside of the function
    //outpp = &inp;
    return;
}