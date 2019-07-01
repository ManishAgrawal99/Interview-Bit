#include<stdio.h>
#include<conio.h>
#include <limits.h>

/**


Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

**/



int reverse(int A) {

    long long  temp = abs(A), rev = 0;

    while (temp)
    {
        rev = rev * 10 + temp % 10;
        if (rev > INT_MAX) return 0;
        temp /= 10;
    }


    return (A < 0 ? -rev : rev);

}


void main(){
    int A = 20912;

    int val = reverse(A);

    printf("%d", val);
}





/**
int reverse(int A) {
    if(A==0){
        return 0;
    }

    int neg = 0;
    if(A<0){
        neg = 1;
        A = A*-1;
    }

    int temp=A;
    long long int rev=0;

    while (temp){
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if(neg){
        rev = rev * -1;
    }

    if(rev>2147483647 || rev<-2147483648 ){
        return 0;
    }

    temp = rev;

    return temp;
}

**/
