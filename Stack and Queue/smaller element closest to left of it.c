/**
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that
    j is maximum possible AND
    j < i AND
    A[j] < A[i]

Elements for which no smaller element exist, consider next smaller element as -1.
**/

#include<stdio.h>
#include<conio.h>

int* prevSmaller(int* A, int n1, int *len1) {
    *len1=n1;
    int *stack=(int *)malloc(*len1*sizeof(int));
    int i=1,j;
    stack[0]=-1;
    for(i=1;i<n1;i++)
    {
        if(A[i-1]<A[i])
        stack[i]=A[i-1];
        else
        {
            j=i-1;
            while(j>0 && stack[j]>=A[i])
            j--;
            stack[i]=stack[j];
        }
    }
    return stack;
}

void main(){
    int A[] = {4,5,2,10,8};
    int n = sizeof(A)/sizeof(A[0]);

    int len1 = 0;
    int* res = prevSmaller(A, n, &len1);

    int i;
    for(i=0;i<len1;i++){
        printf("%d ", res[i]);
    }
}
