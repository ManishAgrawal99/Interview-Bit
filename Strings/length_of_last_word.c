/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int lengthOfLastWord(const char* A){
    int i = strlen(A)-1;
    int count = 0;

    while(i>=0){
        if(A[i]==' ')
            i--;
        else{
            break;
        }
    }

    while(i>=0){
        if(A[i]!=' '){
            count++;
            i--;
        }
        else{
            break;
        }
    }
    return count;
}

void main(){
    char str[] = "Hello World";

    int len = lengthOfLastWord(&str);

    printf("%d", len);
}
