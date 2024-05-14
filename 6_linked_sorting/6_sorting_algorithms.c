#include "6_sorting_algorithms.h"

int main(void){
    //generate array of random numbers
    int nums[LEN_NUMS];
    clock_t start;
    gen_ran_ints(LEN_NUMS,nums);
    //print_arr(LEN_NUMS,nums);
    
    //create linked list
    linked_list_t *listp = (linked_list_t *)malloc(sizeof (linked_list_t));
    listp->num_ele = 0;
    arr_to_linked_list(listp,LEN_NUMS,nums);
    //printLinkedList(listp);
    printf("Sorting linked list:\n");
    start = clock();
    bubble_sort_list_opt(listp);
    printf("bubble_sort_list_opt time: %fs\n",retTime(start,clock()));
    //printLinkedList(listp);
    
    //create linked list
    linked_list_t *list2p = (linked_list_t *)malloc(sizeof (linked_list_t));
    list2p->num_ele = 0;
    arr_to_linked_list(list2p,LEN_NUMS,nums);
    start = clock();
    bubble_sort_list(list2p);
    printf("bubble_sort_listtime: %fs\n",retTime(start,clock()));
    //printLinkedList(list2p);

    //create linked list
    linked_list_t *list3p = (linked_list_t *)malloc(sizeof (linked_list_t));
    list3p->num_ele = 0;
    arr_to_linked_list(list3p,LEN_NUMS,nums);
    start = clock();
    selection_sort_list(list3p);
    printf("selection_sort_list: %fs\n",retTime(start,clock()));
    printLinkedList(list3p);
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

node_t *create_num_node(int num){
    node_t *n1_p = (node_t *)malloc(sizeof (node_t));
    n1_p->num = num;
    
    //printf("Created New Node:\t");
    //printNode(n1_p);
    return n1_p;
}

//swp1,swp2 -> swp2,swp1
void swap_in_list(linked_list_t *list, node_t *swp1, node_t *swp2){
    printListHead(list);
    printNode(swp1);
    printNode(swp2);   
    node_t *nBeforeSwp1 = swp1->previous;
    node_t *nAfterSwp1 = swp1->next;

    node_t *nBeforeSwp2 = swp2->previous;
    node_t *nAfterSwp2 = swp2->next;
    
    if(swp1 == list->first){
        //first element, no before pair
        swp1->next = nAfterSwp2;
        swp1->previous = nBeforeSwp2;
        
        swp2->next = nAfterSwp1;
        swp2->previous = 0; //swp1 was first, no previous
        //swp2->previous = nBeforeSwp1; 

        //nBeforeSwp1->next = swp2;
        nBeforeSwp2->next = swp1;
        nAfterSwp1->previous = swp2;
        nAfterSwp2->previous = swp1;
        //printNode(tAfterPair);
    }
    else if(swp2 == list->last){
        //swp1->next = nAfterSwp2;
        swp1->next = 0;
        swp1->previous = nBeforeSwp2;
        
        swp2->next = nAfterSwp1;
        swp2->previous = nBeforeSwp1; 

        nBeforeSwp1->next = swp2;
        nBeforeSwp2->next = swp1;
        nAfterSwp1->previous = swp2;
        //nAfterSwp2->previous = swp1;
        //printNode(tAfterPair);
    }
    else{
        swp1->next = nAfterSwp2;
        swp1->previous = nBeforeSwp2;
        
        swp2->next = nAfterSwp1;
        //swp2->previous = 0; //swp1 was first, no previous
        swp2->previous = nBeforeSwp1; 

        nBeforeSwp1->next = swp2;
        nBeforeSwp2->next = swp1;
        nAfterSwp1->previous = swp2;
        nAfterSwp2->previous = swp1;
        //printNode(tAfterPair);
    }
    if(swp2 == list->last){
        list->last = swp1;
        list->last->next = 0;
    }
    if(swp1 == list->first){
        list->first = swp2;
        list->first->previous = 0;
    }

    printNode(swp1);
    printNode(swp2);   

    return;
}
node_t *nth_ele_in_list(linked_list_t *listp, int n){
    if(!listp->first){
        //would normally throw an error here
        printf("find ele in list without first\n");
    }
    return nth_node(listp->first, n);
}
node_t *nth_node(node_t *node, int n){
    //recursive function
    if(n != 0)
        if(node->next)
            return nth_node(node->next, n-1);
    return node;
}
void arr_to_linked_list(linked_list_t *listp, int n, int *arr){
    for(int i = 0; i < n; i++){
        node_t *newNode_p = create_num_node(arr[i]);
        if(!(listp->first)){
            //printf("Added first node:\t");
            listp->first = newNode_p;
            //printNode(listp->first);
        }
        if(listp->last){
            newNode_p->previous = listp->last;
            listp->last->next = newNode_p;
            //printNode(listp->last);
        }
        listp->last = newNode_p;
        listp->num_ele++;
        
        //printf("Added new node:\t\t");
        //printNode(newNode_p);
    }
    return;
}
void printLinkedList(linked_list_t *list){
    printf("Print Linked List: (%d elements)\n",list->num_ele);
    int count = 0;
    int *countp = &count;
    printNodes(list->first, countp);
    return;
}
void printListHead(linked_list_t *list){
    printf("Linked List Header:");
    printf("\tnum_ele: %d\n",list->num_ele);
    printf("\tFirst: \t");
    printNode(list->first);
    printf("\tLast: \t");
    printNode(list->last);
}
void printNodes(node_t *node, int *cnt){
    *cnt = *cnt + 1;
    printf("P Node [%d]:",*cnt);
    if(node->num)
        printf("\tnum: %d",node->num);
    if(node->next)
        printf(",\tnext: %d",node->next->num);
    if(node->previous)
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
    if(nodep->next){
        printf(",\tnext: %d",nodep->next->num);
    }
    if(nodep->previous){
        printf(",\tprevious: %d",nodep->previous->num);
    }
    printf("\n");
    
    return;
}

void add_branch_node(node_t *previousp){
    //
    return;
}