/**
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

    You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

    Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4


**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cmpfn(const void *a,const void *b){
     return (*(int*)a - *(int*)b);
}


int nTriang(int* A, int n1) {
    int i,j,k;
    int count=0;
    qsort(A,n1,sizeof(int),cmpfn);
    for(i=n1-1;i>=0;i--)
    {
        j=i-1;
        k=0;

        while(k<j)
        {
            if((A[j]+A[k] > A[i]))
            {
                count = (count+j-k) % 1000000007;
                j--;

            }
            else
                k++;

        }
    }
    return count;
}

void main(){
    int A[] = {4, 6, 13, 16, 20, 3, 1, 12};
    int n = sizeof(A)/sizeof(A[0]);

    int res = nTriang(&A, n);
    printf("%d", res);
}
