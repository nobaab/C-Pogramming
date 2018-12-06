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


void removeDuplicates(struct node *temp)
{
    struct node *temp1, *temp2, *dup;
    temp1 = temp;
    
    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        
        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->next->data)
            {
                dup = temp1->next;
                temp2->next = temp2->next->next;
                delete(dup);
            }
            else
                temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
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


int main ()
{
    int x;
    input(1);
    input(1);
    input(2);
    input(2);
    removeDuplicates(head);
    printData();
}
