/**
Given a positive integer A, return an array of strings with all the integers from 1 to N.
But for multiples of 3 the array should have �Fizz� instead of the number.
For the multiples of 5, the array should have �Buzz� instead of the number.
For numbers which are multiple of 3 and 5 both, the array should have �FizzBuzz� instead of the number.

Look at the example for more details.

Example

A = 5
Return: [1 2 Fizz 4 Buzz]


**/

#include<stdio.h>
#include<conio.h>

void main(){
    int A = 15;

    int i;
    char c;

    char *strs[A];

    for(i=1;i<=A;i++){
        if(i%15==0){
            strs[i-1] = "FizzBuzz";
        }
        else if(i%3==0){
            strs[i-1] = "Fizz";
        }
        else if(i%5==0){
            strs[i-1] = "Buzz";
        }
        else{
            strs[i-1] = i+'0';
        }
    }

    printf("%s", strs[2]);
}
