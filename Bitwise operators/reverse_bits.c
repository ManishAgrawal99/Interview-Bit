/**
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000
=>        00000000000000000000000000000000

return 0

Example 2:

x = 3,

          00000000000000000000000000000011
=>        11000000000000000000000000000000

return 3221225472
**/

#include<stdio.h>
#include<conio.h>

unsigned int reverse(unsigned int A) {
    unsigned int num = 0;
    int i = 0;
    while(A){
        num = num + pow(2,31-i)*(A%2);
        A = A/2;
        i++;
    }

return num;
}

void main(){
    unsigned int A=3;

    unsigned int res = reverse(A);

    printf("%u", res);
}
