/*
You are given an array of N integers, A1, A2 ,…, AN.
Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/

#include<stdio.h>
#include<conio.h>

void main(){
    int i,n;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);

    int A[n];
    printf("Enter the elements in the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("The numbers in the array are: \n");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    int max1 = -1000000000;
    int max2 = -1000000000;
    int min1 = 1000000000;
    int min2 = 1000000000;
    int temp1, temp2;

    for(i=0;i<n;i++){
        temp1 = A[i]+i;
        temp2 = A[i]-i;
        if(temp1>max1){
            max1=temp1;
        }
        if(temp1<min1){
            min1 = temp1;
        }

        if(temp2>max2){
            max2=temp2;
        }
        if(temp2<min2){
            min2 = temp2;
        }
    }

    temp1 = max1 - min1;
    temp2 = max2 - min2;

    if(temp1>temp2){
        printf("%d", temp1);
    }
    else{
        printf("%d", temp2);
    }
}
