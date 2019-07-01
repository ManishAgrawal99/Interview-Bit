/**
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* insertionSortList(node* A) {
    node *res=A,*nxt,*a=A->next,*i;
    res->next=NULL;
    while(a)
    {
        nxt=a->next;
        if(a->val<=res->val)
        {
            a->next=res;
            res=a;
        }
        else
        {
            i=res;
            while(i->next && i->next->val<a->val)
            i=i->next;
            a->next=i->next;
            i->next=a;
        }
        a=nxt;
    }
    return res;
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

    head = insertionSortList(head);
    printf("\n");
    printList(head);
}
