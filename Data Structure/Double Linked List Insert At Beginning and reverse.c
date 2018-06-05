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

void print(int ck){
    struct node* temp1 = head;
    if(ck){
        while(temp1 != NULL){
            printf("%d ", temp1 -> data);
            temp1 = temp1 -> next;
        }
    }
    else{
        while(temp1 -> next != NULL){
            temp1 = temp1 -> next;
        }
        while(temp1 != NULL){
            printf("%d ", temp1 -> data);
            temp1 = temp1 -> prev;
        }
    }
    printf("\n");
    
}

int main(){
    int x, i;
    for(i = 0; i < 5; i++){
        scanf("%d", &x);
        insert(x);
        print(1);
    }
    
    return 0;
}
