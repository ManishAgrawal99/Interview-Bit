/**
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"
**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

char* longestPalindrome(char* A) {

    int start = 0;
    int length = strlen(A);
    int maxLen = 1;

    int low = 0, high;
    int i;

    for(i = 0; i < length; i++){
        low = i-1;
        high = i;
        while((low >= 0) && (high < length) && (A[low] == A[high])){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }

        low = i-1;
        high = i+1;
        while((low >= 0) && (high < length) && A[low] == A[high]){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }

    char* res = (char*)malloc(sizeof(char)*(maxLen+1));

    int ind=0;
    high = start+maxLen;
    while(start != high){
        res[ind] = A[start];
        start++;
        ind++;
    }
    res[ind]='\0';

    return res;
}

void main(){
    char str[] = "aaaabaaa";

    char* res = (char*)malloc(sizeof(char)*strlen(str));

    res = longestPalindrome(&str);

    printf("%s", res);
}
