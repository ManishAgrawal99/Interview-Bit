#include<stdio.h>
#include<conio.h>

/**
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3


**/

int gcd(int A, int B) {
    if(A==B)
        return A;
    else if(A==0)
        return B;
    else if(B==0)
        return A;
    else if(A>B)
        return gcd(A%B,B);
    else
        return gcd(A,B%A);
}

void main(){
    int A = 6;
    int B = 9;

    int res = gcd(A,B);
    printf("%d", res);
}


/**

int gcd(int A, int B) {
    int i,gcd;

    if(A==0){
        return B;
    }
    if(B==0){
        return A;
    }


    for(i=1; i<=A && i<=B; i++){
        if(A%i==0 && B%i==0){
            gcd = i;
        }
    }

    return gcd;
}

**/
