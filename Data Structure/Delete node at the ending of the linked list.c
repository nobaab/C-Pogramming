#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head= NULL, *point =NULL;

void input (int x)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data=x;
    temp -> next =NULL;
    if (head ==NULL && point ==NULL) {
        head =temp;
        point =temp;
    }
    else
        point -> next =temp;
        point = temp;
    
}

void printData()
{
    struct node * temp=head;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp -> next;
    }
    printf("\n");
}

void Delete()
{
    struct node* temp1=head;
    while (temp1 -> next -> next !=NULL) {
        temp1 = temp1 -> next;
    }
    struct node* del =temp1 -> next;
    temp1 -> next =NULL;
    free(del);
}

int main ()
{
    int i,x,n;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&x);
        input(x);
        printData();
    }
    Delete(x);
    printData();
    return 0;
}
