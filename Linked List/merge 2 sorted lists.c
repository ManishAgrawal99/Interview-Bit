/**
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;


node* mergeTwoLists(node* A, node* B) {
    node* t1 = A;
    node* t2 = B;
    node* head = NULL;
    node* curr = NULL;

    while(t1!=NULL && t2!=NULL){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;
        if(t1->val > t2->val){
            newNode->val = t2->val;
            t2 = t2->next;
        }
        else{
            newNode->val = t1->val;
            t1 = t1->next;
        }

        if(head == NULL){
            head = newNode;
        }
        else{
            curr->next = newNode;
        }
        curr = newNode;
    }

    if(t1==NULL){
        while(t2!=NULL){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->next = NULL;

            newNode->val = t2->val;
            t2 = t2->next;

            if(head == NULL){
                head = newNode;
            }
            else{
                curr->next = newNode;
            }
            curr = newNode;
        }
    }
    else{
        while(t1!=NULL){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->next = NULL;

            newNode->val = t1->val;
            t1 = t1->next;

            if(head == NULL){
                head = newNode;
            }
            else{
                curr->next = newNode;
            }
            curr = newNode;
        }
    }
    return head;
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

    //Input list 1
    printf("enter the number of nodes to add in list 1: ");
    scanf("%d", &n);

    node* head1 = NULL;
    node* curr = NULL;

    for(i=0;i<n;i++){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;
        printf("Enter value of node %d: ", i);
        scanf("%d", &t);
        newNode->val = t;

        if(head1==NULL){
            head1 = newNode;
        }
        else{
            curr->next = newNode;
        }
        curr = newNode;
    }


    //Input list 2
    printf("enter the number of nodes to add in list 2: ");
    scanf("%d", &n);

    node* head2 = NULL;
    curr = NULL;

    for(i=0;i<n;i++){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;
        printf("Enter value of node %d: ", i);
        scanf("%d", &t);
        newNode->val = t;

        if(head2==NULL){
            head2 = newNode;
        }
        else{
            curr->next = newNode;
        }
        curr = newNode;
    }

    printList(head1);
    printf("\n");
    printList(head2);

    node* head = mergeTwoLists(head1, head2);

    printf("\n");
    printList(head);

}
