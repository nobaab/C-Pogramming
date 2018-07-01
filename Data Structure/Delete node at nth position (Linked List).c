#include <stdio.h>
#include <stdlib.h>
#define print(a) printf("%d ", a);

struct node
{
    int data;
    struct node* link;
};
struct node* head = NULL;

void insert(int x)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> link = head;
    head = temp;
}

void Delete(int pos){
    struct node* temp = head;
    int i;
    for(i = 0; i < pos - 2; i++){
        temp = temp -> link;
    }
    struct node* temp1 = temp -> link;
    temp -> link = temp1 -> link;
    free(temp1);


}

void printData()
{
    struct node* temp = head;
    while(temp != NULL){
        print(temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}

int main ()
{
    int i, n, x, pos;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        insert(x);
        printData();
    }
    scanf("%d", &pos);
    Delete(pos);
    printData();

    return 0;
}
