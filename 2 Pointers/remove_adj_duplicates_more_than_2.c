/**

Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

**/

#include<stdio.h>
#include<conio.h>

int removeDuplicates(int* A, int n1) {
    int c=0,i=0;
    for( i=0;i<n1;i++)
    {
        if(i<n1-2&&A[i]==A[i+1]&&A[i]==A[i+2])
        continue;
        else
        A[c++]=A[i];
    }
    return c;
}

void main(){
    int A[] = {0,0,0,1,1,2,3,3,3,4};
    int n = sizeof(A)/sizeof(A[0]);

    int i;
    for(i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    int newSize = removeDuplicates(&A, n);

    for(i=0;i<newSize;i++){
        printf("%d ", A[i]);
    }

}
