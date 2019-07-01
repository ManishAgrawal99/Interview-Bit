/**
*The element n is a Noble element if the array has n elements greater than n

**/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int int_cmp(const void *a, const void *b) {
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}

void main(){
    int n1,i,j,count;

    printf("Enter the num of elements in the array: ");
    scanf("%d",&n1);
    int A[n1];

    printf("Enter the elements in the array:\n");
    for(i=0;i<n1;i++){
        scanf("%d", &A[i]);
    }

    qsort(A, n1, sizeof(int), int_cmp);

    for(i=0;i<n1;i++){
        j=i+1;
        if(j<n1){
            while(A[i]==A[j]){
            j++;
            }
        }
        if(A[i]==n1-j){
            printf("\nNoble Element %d is present",A[i]);
            return;
        }
    }

    printf("\nNo Noble Element is present",A[i]);

}
