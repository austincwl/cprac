#include <stdlib.h>
#include <stdio.h>
#define LEN_NUMS 1000
#define SEED 10
#define MAX_RAND 100

typedef struct node_s{
    int num;
    struct node_s *next;
    struct node_s *previous;
} node_t;

typedef struct{
    int num_ele;
    struct node_t *first;
} linked_list_t;


//helper functions
void print_arr(int n,int *arr);
void gen_ran_ints(int n, int *arr);

//linkedl list functions
node_t *create_num_node(int num);
void add_branch_node(node_t *previous);
void print_linked_list(node_t *head);

//sorting functions
void bubble_sort(int n,int *arr);

int main(void){
    int nums[LEN_NUMS];
    gen_ran_ints(LEN_NUMS,nums);
    print_arr(LEN_NUMS,nums);
    return 1;
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
            i = 1;
        }
    }
    return;
}