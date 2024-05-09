#include <stdio.h>
#include <math.h>

void separate(double num, char *signp, int *wholep, double *fracp);
void getTwoInts(int *num1, int *num2);
void getOneDouble(double *dub1);

int main(void)
{
    char hello[] = "starting intro.c";
    printf("%s\n",hello);

    int start;
    int input;
    int *inputp = &input;
    do{
        printf("enter y to start: ");
        scanf("%d",inputp);
        printf("\n");
        start = *inputp;
    }while(start != 1);

    int int1;
    int int2;
    int *int1p = &int1;
    int *int2p = &int2;
    double double1;
    double *double1p = &double1;
    getTwoInts(int1p,int2p);
    getOneDouble(double1p);
    printf("Seperating input double, %f\n",*double1p);
    char sign;
    char *signp = &sign;
    int whole;
    int *wholep = &whole;
    double frac;
    double *fracp = &frac;
    separate(*double1p,signp,wholep,fracp);
    printf("Printing seperated values:\n");
    printf("sign: %c\nwhole: %d\ndec: %f\n",*signp,*wholep,*fracp);
    return (0);
}

void separate(double num, char *signp, int *wholep, double *fracp)
{
    printf("num: %f\n",num);
    printf("sign p: %c\n",*signp);
    double magnitude;
    if(num < 0)
    {
        printf("num < 0\n");
        *signp = '-';
    }
    else if(num==0)
    {
        printf("num < 0\n");
        *signp = ' ';
    }
    else
    {
        printf("num < 0\n");
        *signp = '+';
    }

    printf("sign p: %c\n",*signp);

    magnitude = fabs(num);
    *wholep = floor(magnitude);
    *fracp = magnitude - *wholep;
}

void getTwoInts(int *num1, int *num2)
{
    printf("Enter Int 1: ");
    scanf("%d",num1);
    printf("\nEnter Int 2: ");
    scanf("%d",num2);
    printf("\n");
}

void getOneDouble(double *dub1)
{
    printf("Enter Double: ");
    scanf("%lf",dub1);
    printf("\n");
}
