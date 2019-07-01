/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* deleteDuplicates(node* A) {
    int t;
    node* temp = A;
    node* n;

    while(temp!=NULL && temp->next!=NULL){
        t = temp->val;
        n = temp->next;
        while(n->val==t && n!=NULL){
            if(n->next==NULL){
                temp->next=NULL;
                return A;
            }
            n=n->next;
        }
        temp->next = n;
        temp = temp->next;
    }
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

    head = deleteDuplicates(head);

    printf("\n");
    printList(head);

}
