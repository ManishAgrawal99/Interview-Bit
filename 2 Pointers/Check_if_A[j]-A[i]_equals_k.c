/**

Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

    Example:

    Input :

    A : [1 3 5]
    k : 4

    Output : YES

    as 5 - 1 = 4

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.

**/

#include<stdio.h>
#include<conio.h>

int diffPossible(int* A, int n1, int B) {
    int i,j;
    i=0;
    j=1;

    if(n1<2){
        return 0;
    }

    while(j<n1){
        if(A[j]-A[i]==B){
            return 1;
        }

        if(A[j]-A[i]>B && i<j-1){
            i++;
        }
        else if(A[j]-A[i]>B){
            j++;
        }
        else if(A[j]-A[i]<B){
            j++;
        }
    }
    return 0;
}

void main(){
    int A[] = {1,3,5};
    int n = sizeof(A)/sizeof(A[0]);

    int k = 4;

    int res = diffPossible(&A, n, k);

    printf("%d", res);
}
