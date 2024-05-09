#include <stdio.h>
#include "shapes.h"
//this would normally have more input parameters, maybe overloaded for different shapes
//instead using static values from just the type
void create_shape(figure_t *figure){
    switch((*figure).type){
        case('c'):{
            (*figure).shape.circle.radius = 3;
            break;
        }
        case('s'):{
            figure->shape.square.width = 4;
            break;
        }
        case('r'):{
            (*figure).shape.rectangle.width = 4;
            (*figure).shape.rectangle.length = 5;
            break;
        }
    }
}

void print_shape(figure_t *figure){
    switch((*figure).type){
        case('c'):{
            printf("Circle Radius: %lf\n",(*figure).shape.circle.radius);
            break;
        }
        case('s'):{
            printf("Square Width: %lf\n",figure->shape.square.width);
            break;
        }
        case('r'):{
            printf("Rectangle Width: %lf\n",(*figure).shape.rectangle.width);
            printf("Rectangle Width: %lf\n",(*figure).shape.rectangle.length);
            break;
        }
    }
}