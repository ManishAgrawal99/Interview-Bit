/**
Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

    Example:
    If array A is [4, 1, 1, 2, 1, 3]
    and value elem is 1,
    then new length is 3, and A is now [4, 2, 3]
**/


#include<stdio.h>
#include<conio.h>

int removeElement(int* A, int n1, int B) {
    int i = 0;
    int j;
    for (j = 0; j < n1; j++) {
        if (A[j] != B) {
            A[i] = A[j];
            i++;
        }
    }
    return i;
}

void main(){
    int A[] = {4, 1, 1, 2, 1, 3};
    int n = sizeof(A)/sizeof(A[0]);

    //val to remove
    int k = 1;

    int newSize = removeElement(A, n, k);

    int i;
    for(i=0;i<newSize;i++){
        printf("%d ", A[i]);
    }
}
