/**
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.

    Note 2:
    Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.
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

    int start,end;
    printf("\nEnter start and end position of reversal :");
    scanf("%d %d", &start, &end);

    head = reverseBetween(head, start, end);

    printf("\n");
    printList(head);

}
