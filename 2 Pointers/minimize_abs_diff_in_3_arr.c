/**
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]

Output:

1


**/


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
    int i=0, j=0, k=0;
    int ans=INT_MAX;

    while(i<n1 && j<n2 && k<n3){
        // finding element A[i] closest to B[j]
        while(i<n1 && A[i]<B[j]) i++;
        if(i>0 && abs(A[i]-B[j]) >= abs(A[i-1]-B[j])) i--;

        // finding element C[k] closest to B[j]
        while(k<n3 && C[k]<B[j]) k++;
        if(k>0 && abs(C[k]-B[j]) >= abs(C[k-1]-B[j])) k--;

        // updating answer
        ans = min(ans, max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k])));

        // going to next anchor index j
        j++;
    }
    return ans;
}

void main(){
    int A[] = {1,4,5,8,10};
    int n1 = sizeof(A)/sizeof(A[0]);

    int B[] = {6,9,10};
    int n2 = sizeof(B)/sizeof(B[0]);

    int C[] = {2,3,6,6,10};
    int n3 = sizeof(C)/sizeof(C[0]);

    int res = solve(&A, n1, &B, n2, &C, n3);

    printf("%d", res);
}
