#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN_NUMS 200
#define SEED 1234
#define MAX_RAND 100

//helper functions
void print_arr(int n,int *arr);
void gen_ran_ints(int n, int *arr);
double retTime(clock_t start, clock_t stop);

//sorting functions
void bubble_sort(int n,int *arr);
void bubble_sort_opt(int n,int *arr);

int main(void){
    //generate array of random numbers
    int nums[LEN_NUMS];
    clock_t start;
    clock_t stop;

    gen_ran_ints(LEN_NUMS,nums);
    //printf("Bubble Sort:\n");
    start = clock();
    bubble_sort(LEN_NUMS,nums);
    stop = clock();
    //print_arr(LEN_NUMS,nums);
    printf("Bubble Sort Time: %f\n",retTime(start,stop));

    gen_ran_ints(LEN_NUMS,nums);
    //printf("Bubble Sort Opt:\n");
    start = clock();
    bubble_sort_opt(LEN_NUMS,nums);
    stop = clock();
    //print_arr(LEN_NUMS,nums);
    printf("Bubble Sort Opt Time: %f\n",retTime(start,stop));

    return 1;
}

double retTime(clock_t start, clock_t stop){
    return ((double)stop-(double)start)/CLOCKS_PER_SEC;
}

void gen_ran_ints(int n, int *arr){
    //generate n number of random ints
    srand(SEED);
    for(int i = 0; i < n; i++){
        arr[i] = rand() % MAX_RAND;
    }
    return;
}

void print_arr(int n,int *arr){
    //print array of n integers
    for(int i = 0; i < n; i++){
        printf("Arr [%d] = %d\n",i,arr[i]);
    }
    return;
}

void bubble_sort(int n,int *arr){
    //bubble sort least to greatest
    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]){
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            i = 0;
        }
    }
    return;
}
void bubble_sort_opt(int n,int *arr){
    //bubble sort least to greatest
    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]){
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            i = 0;
        }
    }
    return;
}

/*
void bubble_sort_list(linked_list_t *listp){
    //bubble sort linked list
    int num = listp->num_ele;
    
    for(int i = 0; i < num-1; i++){
        node_t *swap1 = nth_ele_in_list(listp,i);
        node_t *swap2 = nth_ele_in_list(listp,i+1);
        if(swap1->num > swap2->num){
            swap_in_list(listp, swap1,swap2);
            i = -1;
        }
    }

    return;
}

void bubble_sort_list_opt(linked_list_t *listp){
    //bubble sort linked list
    int num = listp->num_ele;
    
    int swapped = 0;
    for(int i = 0; i < num-1; i++){
        node_t *swap1 = nth_ele_in_list(listp,i);
        node_t *swap2 = nth_ele_in_list(listp,i+1);
        if(swap1->num > swap2->num){
            swap_in_list(listp, swap1,swap2);
            swapped = 1;
        }
        if(i == num-2 && swapped){
            swapped = 0;
            i = -1;
        }
    }
    return;
}

void selection_sort_list(linked_list_t *listp){
    int num = listp->num_ele;
    
    for(int i = 0; i < num; i++){
        node_t *indexed = nth_ele_in_list(listp,i);
        node_t *test;
        printf("i: %d\n",i);
        node_t *least = indexed;
        for(int j = i; j < num-1; j++){
            printf("j: %d\n",j);
            test = nth_ele_in_list(listp,j);
            if(test->num < least->num)
                least = test;
            printf("least: %d\n",least->num);
        }
        printLinkedList(listp);
        if(indexed != test && test->num)
            swap_in_list(listp,indexed,least);
    }
}
*/
