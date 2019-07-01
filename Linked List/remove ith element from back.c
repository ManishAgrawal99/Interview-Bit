/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note:

        If n is greater than the size of the list, remove the first node of the list.

Try doing it using constant additional space.

**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;


node* removeNthFromEnd(node* A, int B) {
    node* temp = A;
    int num = 0;

    if(A->next==NULL){
        A=NULL;
        return A;
    }

    // if(B==1){
    //     while(temp->next->next!=NULL){
    //         temp=temp->next;
    //     }
    //     temp->next = NULL;
    //     return A;
    // }


    while(temp!=NULL){
        temp = temp->next;
        num++;
    }

    if(B>num){
        if(A->next!=NULL){
            A = A->next;
        }
        return A;
    }

    if(num==B){
        A=A->next;
        return A;
    }


    int i = 0;
    temp = A;

    while(i<num-B-1){
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;

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

    int pos;
    printf("\nEnter the position of element from back to be removed: ");
    scanf("%d", &pos);

    head = removeNthFromEnd(head, pos);

    printf("\n");
    printList(head);

}
