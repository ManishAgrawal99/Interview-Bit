/**
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

    Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

///Reverse the list
node *reverses(node *head){

    node *curr=head,*prev=NULL,*next1;
    while(curr!=NULL){
        next1=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next1;
    }
    return prev;
}


///Check for palindrome
int lPalin(node* A) {
    //search for mid point of list
     node *slow=A;
     node *newptr;
     node *fast=A;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    int flag;
    if(fast->next==NULL)
        flag=0;

    else if(fast->next->next!=NULL)
        flag=1;

    if(flag==0)
        newptr=reverses(slow->next);
    else
        newptr=reverses(slow);

    node *ptr1,*ptr2;
    ptr1=A;
    ptr2=newptr;

    while(ptr2!=NULL){
        if(ptr1->val!=ptr2->val)
        return 0;

        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

 return 1;
}

void printList(node* head){
    node* t = head;
    while(t!=NULL){
        printf("%d ", t->val);
        t = t->next;
    }
}

void main(){
    int n,i,t;
    printf("enter the number of nodes to add: ");
    scanf("%d", &n);

    node* head = NULL;
    node* curr = NULL;

    for(i=0;i<n;i++){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;
        printf("Enter value of node %d: ", i);
        scanf("%d", &t);
        newNode->val = t;

        if(head==NULL){
            head = newNode;
        }
        else{
            curr->next = newNode;
        }
        curr = newNode;
    }

    printList(head);

    int res = lPalin(head);
    if(res){
        printf("Palindrome");
    }
    else
        printf("NOT a Palindrome");
}
