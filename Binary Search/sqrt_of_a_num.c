/**

Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

**/

#include<stdio.h>
#include<conio.h>

int Sqrt(int A) {
    int lo = 0;
    int hi = 46340;
    int mid = (lo+hi)/2;

    while(lo<=hi){
        mid = (lo+hi)/2;
        if(mid*mid == A){
            return mid;
        }
        else if(mid*mid < A){
            if((mid+1)*(mid+1)>A || mid == 46340){
                return mid;
            }
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
}

void main(){
    int A = 49;

    int res = Sqrt(A);

    printf("%d", res);
}
