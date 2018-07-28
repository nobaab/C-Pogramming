/// @Author Redwan Hossain
/// Daffodil International University, Department of CSE
/// Data structure (lab final) --> Linked list all operation


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head = NULL, *point = NULL;

/// time complexity = O(1)
void insert_at_beginning(int x){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

/// time complexity = O(1)
void insert_at_ending_O_1(int x){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    if(head == NULL){
        head = temp;
        point = temp;
    }
    else {
        point -> next = temp;
        point = temp;
    }
}

/// time complexity = O(n)
void insert_at_ending_O_n(int x){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    if(head == NULL){
        head = temp;
    }
    else {
        struct node* temp1 = head;
        while(temp1 -> next != NULL){
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
    }
}

/// time complexity = O(n)      position start from index 0
void insert_at_nth_position_0(int x, int pos){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    if(pos == 0){                                // if index start from 0 then pos == 0
        temp -> next = head;
        head = temp;
    }
    else {
        struct node* temp1 = head;
        int i;
        for(i = 0; i < pos - 1; i++){            // and then i < pos - 1
            temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        temp1 -> next = temp;
    }
}

/// time complexity = O(n)      position start from index 1
void insert_at_nth_position_1(int x, int pos){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    if(pos == 1){                                // if index start from 1 then pos == 1
        temp -> next = head;
        head = temp;
    }
    else {
        struct node* temp1 = head;
        int i;
        for(i = 0; i < pos - 2; i++){            // and then i < pos - 2
            temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        temp1 -> next = temp;
    }
}

/// time complexity = O(1)
void delete_from_beginning(){
    struct node* del = head;
    head = head -> next;
    free(del);
}

/// time complexity = O(n)
void delete_from_ending(){
    struct node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    struct node* del = temp -> next;
    temp -> next = NULL;
    free(del);
}

/// time complexity = O(n)          position start from index 0
void delete_from_nth_position_0(int pos){
    if(pos == 0){                                // if index start from 0 then pos == 0
        struct node* del = head;
        head  = head -> next;
        free(del);
    }
    else {
        struct node* temp = head;
        int i;
        for(i = 0; i < pos - 1; i++){            // and then i < pos - 1
            temp = temp -> next;
        }
        struct node* del = temp -> next;
        temp -> next  = del -> next;
        free(del);
    }
}

/// time complexity = O(n)          position start from index 1
void delete_from_nth_position_1(int pos){
    if(pos == 1){                                // if index start from 1 then pos == 1
        struct node* del = head;
        head  = head -> next;
        free(del);
    }
    else {
        struct node* temp = head;
        int i;
        for(i = 0; i < pos - 2; i++){            // and then i < pos - 2
            temp = temp -> next;
        }
        struct node* del = temp -> next;
        temp -> next  = del -> next;
        free(del);
    }
}

/// time complexity = O(n)
void delete_data_by_searching(int x){
    struct node* temp = head;
    if(temp -> data == x){
        struct node* del = temp;
        head  = head -> next;
        free(del);
    }
    else {
        int i;
        while(temp -> next -> data != x){
            temp = temp -> next;
        }
        struct node* del = temp -> next;
        temp -> next  = del -> next;
        free(del);
    }
}

/// time complexity = O(n)
void searching(int x){
    struct node* temp = head;
    while(temp != NULL){
        if(temp -> data == x){
            printf("found\n");
            return;
        }
        temp = temp -> next;
    }
    printf("not found\n");
}

/// time complexity = O(n)
int count(){
    int cnt = 0;
    struct node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}

/// time complexity = O(n)
void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    int n, x, pos;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        //        insert_at_beginning(x);
        //        insert_at_ending_O_1(x);
        insert_at_ending_O_n(x);
    }
    print();
    //    scanf("%d %d", &x, &pos);
    //    insert_at_nth_position_0(x, pos);
    //    insert_at_nth_position_1(x, pos);
    //    delete_from_beginning();
    //    delete_from_ending();
    //    scanf("%d", &pos);
    //    delete_from_nth_position_0(pos);
    //    delete_from_nth_position_1(pos);
    scanf("%d", &x);
    delete_data_by_searching(x);
    print();
    scanf("%d", &x);
    searching(x);
    int size = count();
    printf("%d\n", size);
    
    return 0;
}
