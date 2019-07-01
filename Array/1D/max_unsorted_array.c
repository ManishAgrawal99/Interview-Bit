/**
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
    int a[] = {4, 15, 4, 4, 15, 18, 20};
    //int a[] = {1,2,3,4,5,6};

    int n = sizeof(a)/sizeof(int);

    int i;
    int j;

    for (i=0; i<n-1; i++) {
        if (a[i] > a[i+1])
            break;
    }

    if (i==n-1) {
        //*len = 1;
        //a[0] = -1;
        //return a;
        printf("The array is sorted");
        return;
    }

    for (j=n-1; j>0; j--) {
        if (a[j] < a[j-1])
            break;
    }

    int k;
    int min = a[i];
    int max = a[i];

    for (k=i; k<=j; k++) {
        if (a[k] < min) {
            min = a[k];
        } else if (a[k] > max) {
            max = a[k];
        }
    }

    int l,m;

    for (k=0; k<i; k++) {
        if (a[k]>min)
            break;
    }

    l = k;

    for (k=n-1; k>j; k--) {
        if (a[k]<max)
            break;
    }
    m = k;

    //int *b = (int*)malloc(sizeof(int)*(2));
    //*len = 2;

    //b[0] = l;
    //b[1] = m;

    //return b;
    printf("We need to sort from %d to %d", l,m);
    return;

}
