#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
    
};


struct node *head=NULL;

struct node * CreateNode(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next= NULL;
    newnode->prev= NULL;
    return newnode;
}



void insert_at_beginning(int x)
{
    struct node *temp;
    temp= CreateNode(x);
    if(head->next==NULL)
    {
        head->next = temp;
        temp->prev = head;
        return;
    }
    temp->prev=head;
    temp->next= head->next;
    (head->next)->prev = temp;
    head->next = temp;
}


void insert_at_nth_position_0(int x,int position)
{
    struct node *temp;
    temp= CreateNode(x);
    struct node *cur;
    cur=head->next;
    int flag=1;
    
    while(cur->next==NULL && flag<position)
    {
        cur=cur->next;
        flag++;
    }
    
    if(cur->next!=NULL)
    {
        temp->prev=cur;
        temp->next=cur->next;
        (cur->next)->prev=temp;
        cur->next=temp;
    }
    else
    {
        cur->next=temp;
        temp->prev=cur;
        
    }
    
}

void insert_at_ending_O_1(int x)
{
    struct node *temp;
    temp= CreateNode(x);
    if(head->next==NULL)
    {
        head->next = temp;
        temp->prev = head;
        return;
    }
    struct node *cur;
    cur= head->next;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    temp->prev=cur;
    cur->next=temp;
}



void delete_from_beginning()
{
    struct node* del = head;
    head = head -> next;
    free(del);
}


void delete_from_ending()
{
    struct node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    struct node* del = temp -> next;
    temp -> next = NULL;
    free(del);
}

void delete_from_nth_position_0(int pos)
{
    if(pos == 0){
        struct node* del = head;
        head  = head -> next;
        free(del);
    }
    else {
        struct node* temp = head;
        int i;
        for(i = 0; i < pos - 1; i++){
            temp = temp -> next;
        }
        struct node* del = temp -> next;
        temp -> next  = del -> next;
        free(del);
    }
}


void print()
{
    struct node *cur;
    cur= head->next;
    while(cur!=NULL)
    {
        printf("%d\t", cur->data);
        cur= cur->next;
    }
    printf("\n\n");
    
}

int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    head->prev=NULL;
    head->next=NULL;
    int a=1;
    while(a)
    {
        int n;
        printf("Enter your choice:\nOptions:\n1. Insert First\n2. Insert Middle\n3. Insert Last\n4. Delete First\n5. Delete Last\n6. Delete Middle \n7. Print\n");
        scanf("%d", &n);
        if(n==1)
        {
            printf("Enter Data\n");
            int x;
            scanf("%d", &x);
            insert_at_beginning(x);
        }
        
        else if(n==2)
        {
            printf("Enter Data\n");
            int x;
            scanf("%d", &x);
            printf("Enter Position\n");
            int pos;
            scanf("%d", &pos);
            insert_at_nth_position_0(x, pos);
        }
        else if(n==3)
        {
            printf("Enter Data\n");
            int x;
            scanf("%d", &x);
            insert_at_ending_O_1(x);
        }
        
        
        
        
        else if (n==4){
            delete_from_beginning();
        }
        
        else if (n==5){
            delete_from_ending();
        }
        
        
        else if (n==6){
            printf("Enter Position\n");
            int pos;
            scanf("%d",&pos);
            delete_from_nth_position_0(pos);
        }
        
        else if(n==7)
        {
            print();
        }
        else
        {
            printf("Error\n");
            a=0;
        }
    }
}
