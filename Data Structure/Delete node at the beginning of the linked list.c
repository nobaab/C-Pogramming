#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
    
};
struct node* head=NULL;
void insert(int b)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=b;
    temp->next=head;
    head=temp;
}
void print()
{
    struct node* temp1=head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}

void Delete(int b)
{
    struct node* temp=head;
    head = temp -> next;
    free(temp);
}
int main ()
{
    int a,i,b;
    scanf("%d",&a);
    for(i=0; i<a; i++)
    {
        scanf("%d",&b);
        insert(b);
        print();
    }
    Delete(b);
    print();
    //    Delete(b);
    //    print();
    //    Delete(b);
    //    print();
    //    Delete(b);
    //    print();
    
}
