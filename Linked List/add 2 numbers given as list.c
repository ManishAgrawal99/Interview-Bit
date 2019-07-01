/**
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807

Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* listnode_new(int val){
    node* newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


node* addTwoNumbers(node* A, node* B) {
    int carry=0;
    node *head=NULL, *prev;
    while (A || B || carry){
        int val;
        val = carry;
        if (A) {
            val += A->val;
            A = A->next;
        }
        if (B) {
            val += B->val;
            B = B->next;
        }
        if (val > 9) {
            val -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        node *n = listnode_new(val);
        if (!head) {
            head = n;
            prev = head;
        } else {
            prev->next = n;
            prev = n;
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

    node* head = addTwoNumbers(head1, head2);

    printf("\n");
    printList(head);

}
