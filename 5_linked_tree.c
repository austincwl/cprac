#include <stdlib.h>
#include <stdio.h>
#define NUM_NUMS 10

typedef struct node_s{
    int num;
    struct node_s *lower;
    struct node_s *higher;
} node_t;

typedef struct{
    int num_ele;
    struct node_t *first;
} linked_list_t;

void print_arr(int n,int *arr);
void bubble_sort(int n,int *arr);
node_t *create_num_node(int num);
void add_branch_node(node_t *parent, node_t *child);
void print_tree(node_t *head);

int main(void){
    int nums[NUM_NUMS] = {9,7,5,3,1,2,4,6,8,10};
    printf("Input Array:\n");
    int mid = NUM_NUMS/2; //will truncate since int
    printf("Mid Num ind %d: %d\n",mid,nums[mid]);
    print_arr(NUM_NUMS, nums);

    int nums_sorted[NUM_NUMS] = {9,7,5,3,1,2,4,6,8,10};

    bubble_sort(NUM_NUMS,nums_sorted);
    printf("Sorted Array:\n");
    print_arr(NUM_NUMS, nums_sorted);
    
    mid = NUM_NUMS/2; //will truncate since int
    printf("Mid Num ind %d: %d\n",mid,nums_sorted[mid]);
    
    node_t *n1_p;
    n1_p = (node_t *)malloc(sizeof (node_t));
    n1_p->num = nums_sorted[mid];
    
    for(int i = 0; i<NUM_NUMS;i++)
    {
        node_t *next_p = create_num_node(nums[i]);
        //printf("created node with val: %d\n",next_p->num);
        add_branch_node(n1_p,next_p);
    }
    print_tree(n1_p);

    return 1;
}

node_t *create_num_node(int nu){
    node_t *n1_p = (node_t *)malloc(sizeof (node_t));
    n1_p->num = nu;
    return n1_p;
}
void add_branch_node(node_t *parent,node_t *child){
    //inputs head and child to insert
    printf("add_branch_node, parent: %d, child: %d\n",parent->num,child->num);
    if(parent->num == child->num){
        //skip since duplicate
        return;
    }else if(child->num < parent->num){
        //child is less, insert on left
        if(parent->lower){
            add_branch_node(parent->lower,child);
        }
        else{
            parent->lower = child;
        }
    }else{
        if(parent->higher){
            add_branch_node(parent->higher,child);
        }
        else{
            parent->higher = child;
        }
    }
    return;
}

void print_tree(node_t *head){
    printf("Val: %d",head->num);
    if(head->lower){
        printf(", Lower: %d",head->lower->num);
    }
    if(head->higher){
        printf(", Higher: %d",head->higher->num);
    }
    printf("\n");

    if(head->lower){
        print_tree(head->lower);
    }
    if(head->higher){
        print_tree(head->higher);
    }
}

void bubble_sort(int n,int *arr){
    //bubble sort least to greatest
    int i;
    for(i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i = -1; //i is incremented after each run, need to set to -1 to get back to i=0
        }
    }
    return;
}
void print_arr(int n,int *arr){
    //print array
    for(int i=0;i<n;i++){
        printf("Ele %d: %d\n",i,arr[i]);
    }
    return;
}