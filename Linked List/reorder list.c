/**
Given a singly linked list

    L: L0 -> L1 -> ... -> Ln-1 -> Ln,

reorder it to:

    L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 ->

You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* reorderList(node* A) {
    if (!A){return NULL;}
        if (A->next==NULL){ return A;}
        node *p=A;
        node *q= A;


        while (q->next && q->next->next){
            p=p->next;
            q=q->next->next;
        }


        q = p->next;
        while (q->next){
            node* tmp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = tmp;
        }


        q = A;
        while (p!=q && p->next){
            node* tmp = q->next;
            q->next = p->next;
            p->next = p->next->next;
            q->next->next = tmp;
            q=q->next->next;
        }
        return A ;
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

    head = reorderList(head);

    printf("\n");
    printList(head);

}
