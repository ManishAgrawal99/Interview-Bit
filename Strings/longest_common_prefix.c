/**
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]

The answer would be “a”.

**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

char* longestCommonPrefix(char** A, int n1){
    int ind=0;
    int i,j;
    char c;
    int br=0;

    for(i=0;i<strlen(A[0]);i++){
        c = A[0][i];
        if(c == '\0'){
            return A[0];
        }
        for(j=0;j<n1;j++){
            if(A[j][i] != c){
                br=1;
                break;
            }
        }
        if(br){
            break;
        }
    }

    char* res = (char* )malloc(sizeof(char)* (i+1));
    for(j=0;j<i;j++){
        res[j] = A[0][j];
    }
    res[i] = '\0';

    return res;
}

void main(){
    //char arr[3][20];
    int i;
    char** arr = (char**)malloc(3* sizeof(char*));
    for(i=0;i<3;i++)
        *(arr+i) = (char*)malloc(20* sizeof(char));

    strcpy(arr[0], "abcdefgh");
    strcpy(arr[1], "abcefgh");
    strcpy(arr[2], "abcd");

    char* res = longestCommonPrefix(arr, 3);

    printf("%s", res);
}


