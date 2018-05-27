#include <stdio.h>
#define print(a) printf("%d ", a);
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

void insert(int n, int pos){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = n;
    temp -> next = NULL;
    if(pos == 1){
        temp -> next = head;
        head = temp;
    }
    else{
        struct node* temp1 = head;
        int i;
        for(i = 0; i < pos-2; i++){
            temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        temp1 -> next = temp;
    }
}
void printData(){
    struct node* temp = head;
    while(temp != NULL){
        print(temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main ()
{
    int i,x,n,pos;
    scanf("%d",&x);
    for (i=0; i<x; i++) {
        scanf("%d %d",&n ,&pos);
        insert(n,pos);
        printData();
    }
    return 0;
}
