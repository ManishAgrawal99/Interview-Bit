/**


Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120
Number of trailing zeros = 1
So, return 1

0
**/

#include<stdio.h>
#include<conio.h>

int trailingZeroes(int A) {
    int i=5;
    int count=0;
    while(A/i>=1)
    {
        count+=A/i;
        i=i*5;
    }
    return count;
}

void main(){
    int n = 125;

    int count = trailingZeroes(n);

    printf("%d", count);
}
