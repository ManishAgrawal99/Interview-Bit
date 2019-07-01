/**


You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

    X divides A i.e. A % X = 0
    X and B are co-prime i.e. gcd(X, B) = 1

For example,

A = 30
B = 12
We return
X = 5


**/

#include<stdio.h>
#include<conio.h>

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

int cpFact(int A, int B) {
    // int i;
    // int temp;
    // for(i=A;i>=1;i--){
    //     if(A%i==0 && gcd(i,B)==1){
    //         return i;
    //     }
    // }

    while(gcd(A,B)!=1){
        A = A/gcd(A,B);
    }
    return A;
}

void main(){
    int A = 30;
    int B = 12;

    int res = cpFact(A,B);

    printf("%d", res);
}
