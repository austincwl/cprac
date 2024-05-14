#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define LEN_NUMS 20
#define SEED 10
#define MAX_RAND 100

//helper functions
void print_arr(int n,int *arr);
void gen_ran_ints(int n, int *arr);
double retTime(clock_t start, clock_t stop);

//linked lists
typedef struct node_s{
    int num;
    struct node_s *next; //need 'struct' keyword when using tag name
    struct node_s *previous;
} node_t;

typedef struct linked_list_s{
    int num_ele;
    struct node_s *first;
    struct node_s *last;
} linked_list_t;

//linkedl list functions
node_t *create_num_node(int num);
void printNodes(node_t *node, int *cnt);
void printNode(node_t *node);
void add_branch_node(node_t *previous);
node_t *nth_ele_in_list(linked_list_t *listp, int n);
node_t *nth_node(node_t *node, int n);
void printLinkedList(linked_list_t *list);
void arr_to_linked_list(linked_list_t *listp, int n, int *arr);
void swap_in_list(linked_list_t *list, node_t *swp1, node_t *swp2);
void printListHead(linked_list_t *list);

//sorting functions
void bubble_sort(int n,int *arr);
void bubble_sort_list(linked_list_t *listp);
void bubble_sort_list_opt(linked_list_t *listp);
void selection_sort_list(linked_list_t *listp);