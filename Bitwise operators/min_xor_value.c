/**
Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Examples :
Input
0 2 5 7
Output
2 (0 XOR 2)
Input
0 4 7 9
Output
3 (4 XOR 7)

Constraints:
2 <= N <= 100 000
0 <= A[i] <= 1 000 000 000

**/

#include<stdio.h>
#include<conio.h>
#include<limits.h>

int int_cmp(const void *a, const void *b){
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}

int findMinXor(int* A, int n1) {
    qsort(A, n1, sizeof(int), int_cmp);
    int min = INT_MAX;
    int t,i;
    for(i=0;i<n1-1;i++){
        t = A[i]^A[i+1];
        if(t<min){
            min = t;
            if(min==0){
                return 0;
            }
        }
    }
    return min;
}

void main(){
    int A[] = {0,2,5,7};
    int n = sizeof(A)/sizeof(A[0]);

    int min  = findMinXor(&A, n);

    printf("%d", min);
}
