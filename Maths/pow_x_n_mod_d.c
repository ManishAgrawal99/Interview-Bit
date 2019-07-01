/**


Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.


Logic
(ab) mod p = ( (a mod p) (b mod p) ) mod p

For example a = 50,  b = 100, p = 13
50  mod 13  = 11
100 mod 13  = 9

(50 * 100) mod 13 = ( (50 mod 13) * (100 mod 13) ) mod 13
or (5000) mod 13 = ( 11 * 9 ) mod 13
or 8 = 8
**/

#include<stdio.h>
#include<conio.h>

int powmod(int x, int n, int d) {
    int temp;
    long long a = x%d;
    long long res=1;

    if(x==0)
        return 0;
    if (n == 0) return 1 % d;

    while(n>0){
        if(n % 2 == 1){
            res = (res * a) % d;
            n--;
        }
        else{
            a=(a * a) % d;
            n = n>>1;
        }
    }

    if(res < 0){
        res = (res + d) % d;
    }

    return (int)res;
}


void main(){
    int x = 12;
    int n = 2;
    int d = 10;

    int res = powmod(x,n,d);

    printf("%d", res);
}
