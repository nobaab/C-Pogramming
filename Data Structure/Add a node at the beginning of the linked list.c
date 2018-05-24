#include <stdio.h>
struct node{
    int data;
    struct node* next;
    
};
struct node* head=NULL;

void insert(int n)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data=n;
    temp -> next = head;
    head =temp;
}

void print(){
    struct node* temp1=head;
    while (temp1 !=NULL) {
        printf("%d ",temp1->data);
        temp1 = temp1 -> next;
    }
    printf("\n");
}

int main ()
{
    int i, n, x;
    scanf("%d",&x);
    for (i=0; i<x; i++) {
        scanf("%d",&n);
        insert(n);
        print();
    }
}
