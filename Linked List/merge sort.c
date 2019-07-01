/**
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;


node* mergeTwoLists(node* A, node* B) {
    node *ans,*ptr1=A,*ptr2=B;
    if(A->val<B->val){
        ans=A;
        ptr1=ptr1->next;
    }
    else{
        ans=B;
        ptr2=ptr2->next;
    }
    while(ptr1 && ptr2)
    {
        if(ptr1->val<ptr2->val)
        {
            ans->next=ptr1;
            ans=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            ans->next=ptr2;
            ans=ptr2;
            ptr2=ptr2->next;
        }
    }
    if(ptr2)
    ans->next=ptr2;
    else
    ans->next=ptr1;
    if(A->val<B->val)       return A;
    else                    return B;
}
void mergesort(node **A)
{
    node *start=*A,*slow=*A,*fast=*A,*prev=NULL;
    int len;
    len=0;
    while(fast && fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        len=len+2;
    }
    if(fast)        len++;
    if(len<=1)      return;
    if(len>1)
    {

        prev->next=NULL;
        mergesort(&start);
        mergesort(&slow);
        *A=mergeTwoLists(start,slow);
    }
}
node* sortList(node* A) {
    if(A==NULL || A->next==NULL)
        return A;
    mergesort(&A);
    return A;
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

    head = sortList(head);
    printf("\n");
    printList(head);
}
