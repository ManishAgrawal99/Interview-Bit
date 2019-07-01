/**
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input :

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3.
**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* detectCycle(node* A){
    node *fast, *slow;

    if(A->next->next==NULL){
        return NULL;
    }

    fast = A->next->next;
    slow = A->next;

    while(fast!=slow){
        slow = slow->next;
        if(fast->next == NULL || fast->next->next==NULL){
            return NULL;
        }
        else{
            fast = fast->next->next;
        }
    }

    slow = A;

    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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

    int pos;
    printf("\nEnter the start position of the cycle and -1 if no cycle: ");
    scanf("%d",&pos);

    node* head = NULL;
    node* curr = NULL;
    node* cyc;

    for(i=0;i<n;i++){
        node* newNode = (node*)malloc(sizeof(node));
        if(pos == i+1){
                cyc = newNode;
        }
        newNode->next = cyc;
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

    //printList(head);
    cyc = detectCycle(head);

    if(cyc == NULL){
        printf("\nNo Cycles Detected");
    }
    else{
        printf("\nCycles Detected At %d", cyc->val);
    }

    printf("\n");
    //printList(head);

}
