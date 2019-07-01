/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

*/
#include<stdio.h>
#include<conio.h>

void main(){
    int i,j,n1,n2;
    printf("Enter the number of elements in the array");
    scanf("%d",&n1);

    int A[n1];
    printf("Enter the elements in the array:\n");
    for(i=0;i<n1;i++){
        scanf("%d",&A[i]);
    }

    printf("The number represented by the array is: ");
    for(i=0;i<n1;i++){
        printf("%d",A[i]);
    }

    printf("\n\nAfter adding 1: ");
    int carry=1;
    int zeros = 0;

    int oind=n1;
    n2=n1+1;
    int B[n2];

    for(i=n1-1; i>=0; i--){
        B[oind] = (A[i] + carry)%10;
        oind--;
        carry = (A[i]+carry)/10;
    }
    B[oind] = carry;

    for(i=0;i<n2&&B[i]==0;i++){
        zeros++;
    }

    int out[n2-zeros];
    for(i=0;i<n2-zeros;i++){
        out[i] = B[zeros+i];
    }

    //Out[] contains the final array with n2-zeros elements
    for(i=0;i<n2-zeros;i++){
        printf("%d",out[i]);
    }
}
