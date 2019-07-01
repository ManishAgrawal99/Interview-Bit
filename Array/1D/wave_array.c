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

    int i,j;
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int A[n];
    int res[n];

    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    qsort(A, n, sizeof(int), int_cmp);

    i=1;
    j=0;
    while(i<n){
       res[j] = A[i];
       j+=2;
       i+=2;
    }
    j=1;
    i=0;
    while(i<n){
        res[j] = A[i];
        j+=2;
        i+=2;
    }

    if(n%2==1){
        res[n-1] = A[n-1];
    }

    printf("The wave form is :\n");
    for(i=0;i<n;i++){
        printf("%d ", res[i]);
    }
}
