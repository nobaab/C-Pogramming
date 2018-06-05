#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int x){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = x;
    temp -> next = NULL;
    if(head != NULL){
        temp -> next = head;
        head -> prev = temp;
    }
    head = temp;
    
}

void print(struct node* temp1){
    
    if(temp1 == NULL){ return; }
    printf("%d ", temp1 -> data);
    print(temp1 -> next);
    
}
int main(){
    int x, i;
    for(i = 0; i < 5; i++){
        scanf("%d", &x);
        insert(x);
        print(head);
        printf("\n");
    }
    return 0;
}

