/**
    Given two sorted integer arrays A and B, merge B into A as one sorted array.
    If the number of elements initialized in A and B are m and n respectively,
    the resulting size of array A after your code is executed should be m + n

    Input :
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
**/

#include<stdio.h>
#include<conio.h>

void merge(int* A, int n1, int* B, int n2) {
    int i = 0;
    int j = 0;
    int k = 0;
    int *C = (int*)malloc((n1+n2)*sizeof(int));

    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
        }
        k++;

    }

    while(i < n1)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        C[k] = B[j];
        j++;
        k++;
    }
    C[k++] = A[i];
    C[k++] = B[j];
    //return C;

    for(i=0; i<n1+n2; i++){
        printf("%d ", C[i]);
    }


}


void main(){
    int n1, n2, i;

    n1 = 5;
    n2 = 6;

    int A[] = {1,3,5,7,9};
    int B[] = {2,4,6,8,9,10};



    for(i=0; i<n1; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    for(i=0; i<n2; i++){
        printf("%d ", B[i]);
    }
    printf("\n");

    merge(&A, n1, &B, n2);
}
