#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};
struct node* head=NULL, *point=NULL;

void insert(int x){
    struct node * temp= (struct node*) malloc (sizeof(struct node));
    temp -> data=x;
    temp -> next = NULL;
    if (head==NULL && point == NULL) {
        head=temp;
        point=temp;
    }
    else{
        point -> next = temp;
        point = temp;
    }
    
}

void printdata ()
{
    struct node* temp=head;
    while (temp!=NULL) {
        printf("%d",temp -> data);
        temp= temp -> next;
    }
    printf("\n");
}

int main ()
{
    int i,x,n;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&x);
        insert(x);
        printdata();
    }
    return 0;
}
