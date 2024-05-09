#include <stdio.h>
#include <math.h>
#include "shapes.h"
#define PI 3.14159;

int main(void){
    figure_t cir1,squ1,rec1;
    cir1.type = 'c';
    create_shape(&cir1);
    print_shape(&cir1);
    squ1.type = 's';
    create_shape(&squ1);
    print_shape(&squ1);
    rec1.type = 'r';
    create_shape(&rec1);
    print_shape(&rec1);
    return (1);
}