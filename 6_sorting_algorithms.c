#include <stdlib.h>
#include <stdio.h>
#define LEN_NUMS 10
#define SEED 10
#define MAX_RAND 100

typedef struct node_s{
    int num;
    struct node_s *next; //need 'struct' keyword when using tag name
    struct node_s *previous;
} node_t;

typedef struct{
    int num_ele;
    node_t *first;
    node_t *last;
} linked_list_t;


//helper functions
void print_arr(int n,int *arr);
void gen_ran_ints(int n, int *arr);

//linkedl list functions
node_t *create_num_node(int num);
void printNodes(node_t *node, int *cnt);
void printNode(node_t *node);
void add_branch_node(node_t *previous);
void printLinkedList(linked_list_t *list);
void arr_to_linked_list(linked_list_t *listp, int n, int *arr);

//sorting functions
void bubble_sort(int n,int *arr);

int main(void){
    //generate array of random numbers
    int nums[LEN_NUMS];
    gen_ran_ints(LEN_NUMS,nums);
    print_arr(LEN_NUMS,nums);
    
    //create linked list
    linked_list_t *list;
    list->num_ele = 0;
    arr_to_linked_list(list,LEN_NUMS,nums);
    printLinkedList(list);

    return 1;
}

node_t *create_num_node(int num){
    node_t *n1_p = (node_t *)malloc(sizeof (node_t));
    n1_p->num = num;
    
    printf("Created New Node:\t");
    printNode(n1_p);
    return n1_p;
}
void arr_to_linked_list(linked_list_t *listp, int n, int *arr){
    
    for(int i = 0; i < n; i++){
        node_t *newNode_p = create_num_node(arr[i]);
        if(!listp->first){
            printf("Added first node:\t");
            listp->first = newNode_p;
            printNode(listp->first);
        }
        if(listp->last){
            //printf("node:\n");
            //printNode(listp->last);
            //printf("has a previous element:\n");
            printf("Last node in list:\t");
            listp->last->next = newNode_p;
            printNode(listp->last);
        }
        listp->last = newNode_p;
        listp->num_ele++;
        
        printf("Added new node:\t\t");
        printNode(newNode_p);
        
        //printf("List State: \tnum_ele: %d
    }

    return;
}
void printLinkedList(linked_list_t *list){
    printf("Print Linked List: (%d elements)\n",list->num_ele);

    int *count;
    *count = 0;

    printNodes(list->first, count);
    return;
}
void printNodes(node_t *node, int *cnt){
    *cnt++;
    printf("Print Node [%d]:",*cnt);
    if(node->num)
        printf("\tnum: %d",node->num);
    if(node->next->num)
        printf(",\tnext: %d",node->next->num);
    if(node->previous->num)
        printf(",\tprevious: %d",node->previous->num);
    printf("\n");
    
    if(node->next)
        printNodes(node->next,cnt);
    return;
}
void printNode(node_t *nodep){
    printf("Print Node:");
    if(nodep->num){
        printf("\tnum: %d",nodep->num);
    }
    if(nodep->next->num){
        printf(",\tnext: %d",nodep->next->num);
    }
    if(nodep->previous->num){
        printf(",\tprevious: %d",nodep->previous->num);
    }
    printf("\n");
    
    return;
}

void add_branch_node(node_t *previousp){
    //
    return;
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