#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head =NULL;

void input(int x)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node*));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}
void search(struct node* temp, int key)
{
    while (temp!=NULL) {
        if (temp -> data==key) {
            printf("Found\n");
            return ;
        }
        temp = temp -> next;
    }
    printf("Not Found\n");
}

void print()
{
    struct node* temp1 = head;
    while (temp1!=NULL) {
         printf("%d ",temp1 -> data);
        temp1 = temp1 -> next;
    }
   
    printf("\n");
}
int main()
{
    int i,x,n,key;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&x);
        input(x);
        print();
    }
    scanf("%d",&key);
    search(head, key);
    
}
