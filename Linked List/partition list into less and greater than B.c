/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* partition(node* A, int B){
    node *lt = NULL, *gt = NULL;
    node *l=NULL, *g=NULL;

    node* temp = A;

    if(A==NULL || A->next == NULL){
        return A;
    }

    while(temp!=NULL){
        if(temp->val < B){
            if(lt==NULL){
                lt = temp;
                l = lt;
            }
            else{
                l->next = temp;
                l = temp;
            }
        }
        else{
            if(gt==NULL){
                gt = temp;
                g = gt;
            }
            else{
                g->next = temp;
                g = temp;
            }
        }
        temp = temp->next;
    }
    if(l!=NULL)
        l->next = NULL;
    if(g!=NULL)
        g->next = NULL;

    if(lt!=NULL){
        l->next = gt;
        return lt;
    }
    else{
        return gt;
    }
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

    int num;
    printf("\nEnter the number to partition the elements from: ");
    scanf("%d", &num);

    head = partition(head, num);

    printf("\n");
    printList(head);

}
