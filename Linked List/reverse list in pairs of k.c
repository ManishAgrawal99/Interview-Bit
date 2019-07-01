/**
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

    NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

**/

#include<stdio.h>
#include<conio.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* reverseBetween(node* head, int m, int n) {
   int i = 1;
   node *prev = head, *p  = head, *start, *temp = NULL;
    while(i <= n){
        if(i < m){
            prev = p;
            p = p->next;
        }
        else if(i == m){
            start = p;
        }
        if(i>=m && i<=n){
            node *nxt = p->next;
            p->next = temp;
            temp = p;
            p = nxt;
        }
        i++;
    }
    //if(p ==NULL)printf("%d\n",i);
    if(m == 1)head = temp;
    else prev->next = temp;
    start->next = p;
    return head;
}


node* reverseList(node* A, int B){
    node* temp = A;
    int i = 1, j = 1, k = B;

    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }

    count  = count/B;

    for(i=1;i<=count;i++){
        A = reverseBetween(A, j, k);
        j += B;
        k+=B;
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
    printf("\nenter the number of nodes to add: ");
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

    int B;
    printf("Enter K to reverse in sets of K: ");
    scanf("%d", &B);

    head = reverseList(head, B);

    printf("\n");
    printList(head);

}

