/**
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2


**/

#include<stdio.h>
#include<conio.h>
#include<limits.h>

int divide(int dividend, int divisor) {

    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
    long long newdividend = labs(dividend);
    long long newdivisor = labs(divisor);
    int ans = 0;

    while (newdividend >= newdivisor) {
        long long tmp = newdivisor;
        int m = 1;
        while (newdividend >= (tmp << 1)) {
            m = m << 1;
            tmp = tmp << 1;
        }
        newdividend -= tmp;
        ans += m;
    }
    return ans * sign;
}

void main(){
    int A = 7;
    int B = 2;
    int res = divide(A,B);

    printf("%d",res);
}
