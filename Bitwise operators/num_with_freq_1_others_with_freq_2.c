/**
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3
**/

#include<stdio.h>
#include<conio.h>

int singleNumber(const int* A, int n1) {
    int i;
    int res = 0;
    for(i=0;i<n1;i++){
        res = res ^ A[i];
    }
    return res;
}

void main(){
    int A[] = {1, 2, 2, 3, 1};
    int n = sizeof(A)/sizeof(A[0]);

    int res = singleNumber(A,n);

    printf("%d", res);
}
