#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int x){
    struct node* temp = (struct node*) malloc (sizeof(struct node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void pop(){
    if(head == NULL){
        printf("stack is empty\n");
        return;
    }
    struct node* del = head;
    head = head -> next;
    free(del);
}

void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int top(){
    if(head == NULL){
        return -1;
    }
    return head -> data;
}

int main(){
    push(5);
    //print();
    push(6);
    //print();
    push(7);
    //print();
    push(2);
    //print();
    pop();
    print ();
    if(top() == -1){
        printf("stack is empty\n");
    }
    else {
        int x = top();
        printf("top value = %d\n", x);
    }
}
