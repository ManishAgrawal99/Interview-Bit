/**
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Input : 4
Output: 2 + 2 = 4
**/

#include<stdio.h>
#include<conio.h>

int isPrime(int a){
    int i;
    for(i=2;i<=(a/2)+1;i++){
        if(a%i == 0){
            return 0;
        }
    }
    return 1;
}

void main(){
    int A = 8;
    int* res = (int*)malloc(sizeof(int)*2);
    res[0] = 2;
    res[1] = 2;

    if(A==4){
        printf("%d and %d", 2,2);
        return 0;
    }

    int start = 3;
    while(start<=(A/2)+1){
        if(isPrime(start) && isPrime(A-start)){
            res[0] = start;
            res[1] = A-start;
            //return res;
            printf("%d and %d", res[0], res[1]);
            return 0;

        }
        start+=2;
    }
}


