/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;


///Rotate list to right by B
node* rotateRight(node* A, int B) {
    if(B==0){
        return A;
    }

    node* t1 = A;
    int num = 0;
    while(t1!=NULL){
        num++;
        t1 = t1->next;
    }

    B = B%num;

    if(B==0){
        return A;
    }

    int i = 0;
    t1=A;
    while(i<num-B-1){
        t1 = t1->next;
        i++;
    }
    node* t2 = t1->next;
    t1->next = NULL;

    node* head = t2;
    while(t2->next!=NULL){
        t2 = t2->next;
    }
    t2->next = A;
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

    int pos;
    printf("\nEnter the position to shift right: ");
    scanf("%d", &pos);

    head = rotateRight(head, pos);

    printf("\n");
    printList(head);

}
