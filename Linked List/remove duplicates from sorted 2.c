/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* deleteDuplicates(node* A) {

    if(A==NULL || A->next==NULL){
        return A;
    }

    int t,f=0;
    node* temp = A;
    node* n;
    node* prev = NULL;

    while(temp!=NULL && temp->next!=NULL){
        t = temp->val;
        n = temp->next;
        if(t!=n->val){
            prev = temp;
            f=1;
        }

        while(n->val==t && n!=NULL){
            if(n->next==NULL){
                if(prev==NULL){
                    A=NULL;
                    return A;
                }
                prev->next=NULL;
                return A;
            }
            n=n->next;
        }
        if(prev == NULL){
            A=n;
            temp = A;
            if(temp->next==NULL){
                return A;
            }
            n=temp->next;
        }

        else if(f==0){
            if(prev!=NULL)
                prev->next = n;
            temp = n;
            if(temp->next==NULL){
                return A;
            }
        }
        else{
            temp = temp->next;
            if(temp->next==NULL){
                return A;
            }
        }
        f=0;
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
