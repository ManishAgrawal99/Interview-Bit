#include<stdio.h>
#include<conio.h>



/**
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4
**/

int singleNumber(const int* A, int n1) {
    int first = 0;
    int second = 0;

    int i;
    for(i=0;i<n1;i++){
        first = (first ^ A[i]) & ~second;
        second = (second ^ A[i]) & ~first;
    }
    return first;
}

void main(){
    int A[] = {1, 2, 2, 2};
    int n = sizeof(A)/sizeof(A[0]);

    int res = singleNumber(A,n);

    printf("%d", res);
}
