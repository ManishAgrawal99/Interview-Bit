/**
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* reverseList(node* A) {
    if(A==NULL || A->next == NULL){
        return A;
    }

    node* curr, *prev, *nxt;

    prev = NULL;
    curr = A;
    nxt = A->next;

    while(curr->next!=NULL){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if(curr->next!=NULL){
            nxt = curr->next;
        }
    }
    curr->next = prev;
    A=curr;
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

    head = reverseList(head);

    printf("\n");
    printList(head);

}
