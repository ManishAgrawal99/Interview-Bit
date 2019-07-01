/**

Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

**/

#include<stdio.h>
#include<conio.h>

void sortColors(int* A, int n1) {
    int i;
    int a = 0;
    int b = 0;
    int c = 0;

    for(i=0;i<n1;i++){
        if(A[i]==0){
            a++;
        }
        if(A[i]==1){
            b++;
        }
        if(A[i]==2){
            c++;
        }
    }

    for(i=0;i<a;i++){
        A[i] = 0;
    }
    for(i=a;i<a+b;i++){
        A[i] = 1;
    }
    for(i=a+b;i<a+b+c;i++){
        A[i] = 2;
    }
}

void main(){
    int A[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(A)/sizeof(A[0]);

    sortColors(&A, n);

    int i;
    for(i=0;i<n;i++){
        printf("%d ", A[i]);
    }
}
