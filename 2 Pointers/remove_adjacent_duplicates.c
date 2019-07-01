/**
Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

    Example:
    Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2].

**/

#include<stdio.h>
#include<conio.h>

int removeDuplicates(int* A, int n1){
    int j;
    int i = 1;

    for(j=1;j<n1;j++){
        if(A[j]==A[j-1]){

        }
        else{
            A[i] = A[j];
            i++;
        }
    }

    return i;
}

void main(){
    int A[] = {1,2,1,2,1,1,1,2,1,1,2,2};
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
