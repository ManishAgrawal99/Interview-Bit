/**
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Input :
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input :
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]

**/


#include<stdio.h>
#include<conio.h>


int* intersect(const int* A, int n1, const int* B, int n2, int *len1) {
    int i=0,j=0,k=0;

    int temp;
    if(n1>n2){
        temp = n2;
    }
    else{
        temp = n1;
    }
    int*C = (int*)malloc(sizeof(int)*(temp));

    while(i<n1 && j<n2){
        if(A[i]==B[j]){
            C[k] = A[i];
            k++;
            i++;
            j++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else{
            j++;
        }
    }
    *len1 = k;
    return C;
}

void main(){
    int A[] = {2, 3, 3, 4, 5, 6};
    int n1 = sizeof(A)/sizeof(A[0]);

    int B[] = {1,3,5};
    int n2 = sizeof(B)/sizeof(B[0]);

    int* len1;

    int* res = intersect(&A, n1, &B, n2, &len1);

    int i;
    for(i=0;i<len1;i++){
        printf("%d ", res[i]);
    }
}
