/**


Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False


**/

#include<stdio.h>
#include<conio.h>

int isPalindrome(int A) {
    int rev = 0, temp = A;

    while (temp)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    return (A < 0 ? 0 : rev == A);
}

void main(){
    int A = 12211;

    if(isPalindrome(A)){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
}
