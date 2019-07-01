#include<stdio.h>
#include<conio.h>

void main(){
    int i, n, m;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    printf("Enter the num of pos to rotate: ");
    scanf("%d", &m);

    printf("The entered array is:\n");
    for(i=0;i<n;i++){
        printf("%d ", A[i]);
    }

    printf("\n\nThe rotated array is:\n");
    for(i=0;i<n;i++){
        printf("%d ", A[(i+m)%n]);
    }
}
