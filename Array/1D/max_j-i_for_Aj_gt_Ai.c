/**
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.'

A : [3 5 4 2]

Output : 2
for the pair (3, 4)

**/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int maximumGap(const int* A, int n1)
{
    int i,j,c;
    int max=-10000;
    int *s=malloc(sizeof(int)*n1);
    int top=-1;

    for(i=0;i<n1;i++)
    {
        if(top==-1 || A[s[top]]>A[i])
            s[++top]=i;
        else
        {
            j=top;
            while(j>=0)
            {
                if(A[i]>=A[s[j]])
                {
                    c=i-s[j];
                    if(c>max) max=c;
                }
                else break;
                j--;
            }
        }
    }
    if(max==-10000)
        return 0;
    return max;
}

void main(){
    int i,n;
    int A[] = {3,5,4,2};
    n = sizeof(A)/sizeof(int);

    int max = maximumGap(A, n);

    printf("%d", max);

}
