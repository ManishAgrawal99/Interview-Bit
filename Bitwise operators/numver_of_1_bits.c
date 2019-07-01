/**
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011

so the function should return 3.
**/

#include<stdio.h>
#include<conio.h>

int numSetBits(unsigned int A) {
    int count = A%2;

    while(A>0){
        A = A/2;
        if(A%2==1){
            count++;
        }
    }
    return count;
}

void main(){
    int A = 11;
    int num = numSetBits(A);

    printf("%d", num);
}
