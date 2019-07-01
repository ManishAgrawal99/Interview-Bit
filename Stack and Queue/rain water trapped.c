/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
**/

#include<stdio.h>
#include<conio.h>

int trap(const int* A, int n)
{
    int left = 0; int right = n - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;

    while(left <= right)
    {
        if(A[left] <= A[right])
        {
            if(A[left] >= maxleft) maxleft = A[left];
            else res += maxleft-A[left];
            left++;
        }
        else
        {
            if(A[right] >= maxright) maxright = A[right];
            else res += maxright - A[right];
            right--;
        }
    }

    return res;
}

void main(){
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    int n = sizeof(A)/sizeof(A[0]);

    int water = trap(A, n);

    printf("%d", water);
}


/**
///using stack

struct Listnode
{
    int val;
    struct ListNode *next;
};
typedef struct Listnode lnode;
lnode *spush(lnode *,int );
lnode *spop(lnode *);
int sisempty(lnode *);
int trap(const int* A, int n1)
{
    int i=0,r=0,a,w,h,t;
    lnode *head=NULL;
    while(A[i]==0)
    {
        i++;
    }
    head=spush(head,i);
    i++;
    while(i<n1)
    {
        h=head->val;
        h=A[h];
        if(A[i]>=h)
        {
            w=0;
            t=0;
            while(h<=A[i])
            {
                a=head->val;
                w=i-a-1;
                r=r+((A[a]-t)*w);
                t=A[a];
                head=spop(head);
                if(head==NULL)
                 break;
                h=head->val;
                h=A[h];
                if(h>A[i])
                {
                    a=head->val;
                    w=i-a-1;
                    r=r+((A[i]-t)*w);
                    break;

                }
            }
            head=spush(head,i);
        }
        else
        {
            if(A[i]!=0)
            {
                a=head->val;
                w=i-a-1;
                r=r+(w*A[i]);
                head=spush(head,i);
            }
        }
        i++;
    }
    return r;
}
lnode *spush(lnode *head,int c)
{
    lnode *t;
    if(head==NULL)
    {
        head=(lnode *)malloc(sizeof(lnode ));
        head->val=c;
        head->next=NULL;
    }
    else
    {
        t=(lnode *)malloc(sizeof(lnode ));
        t->val=c;
        t->next=head;
        head=t;
    }
    return head;
}
lnode *spop(lnode *head)
{
    lnode *t;
    if(head==NULL)
    {
        return head;
    }
    else
    {
        t=head;
        head=head->next;
        free(t);
    }
    return head;
}
int sisempty(lnode *head)
{
    if(head==NULL)
     return 1;
    else
     return 0;
}
**/
