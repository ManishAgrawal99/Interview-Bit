/**
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]


**/

#include<stdio.h>
#include<conio.h>

void arrange(int* A, int n1) {
    int i;
    for(i=0;i<n1;i++){
        A[i] = A[i] + (A[A[i]]%n1)*n1;
    }
    for(i=0;i<n1;i++){
        A[i] = A[i]/n1;
    }
}

void main(){
    int A[] = { 4, 0, 2, 1, 3 };
    int n1 = 5;

    arrange(&A, n1);

    int i;
    for(i=0;i<n1;i++){
        printf("%d ",A[i]);
    }
}
