/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int isPalindrome(char* A) {
    int i=0;

    while(A[i]){
        if(A[i]>='a' && A[i]<='z'){
            A[i] = 'A'+A[i]-'a';
        }
        i++;
    }

    int l =0,r=i-1;
    while(l<r){

    if(!(A[l]>='A'&&A[l]<='Z' || A[l]>='0' && A[l]<='9')){
        l++;
        continue;
    }

    if(!(A[r]>='A'&&A[r]<='Z' || '0'<=A[r] && A[r]<='9')){
        r--;
        continue;
    }

    if(A[l]==A[r]){
        l++;
        r--;
    }
    else
        return 0;
    }
    return 1;
}

void main(){
    char A[] = "A man, a plan, a canal: Panama";

    if(isPalindrome(&A)){
        printf("Palindrome");
    }
    else{
        printf("NOT Palindrome");
    }
}
