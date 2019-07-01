/**


You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2

**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void computeLPSArray(char* pat, int M, int* lps){
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0


    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int solve(char* A) {
    int origLen = strlen(A);
    int M=origLen;

    int i;
    char* temp = (char*)malloc(sizeof(char)*M*2+2);

    for(i=0;i<M;i++){
        temp[i] = A[i];
    }
    temp[M] = ';';

    i=M+1;
    int ind = M-1;

    for(i=M+1;i<=2*M;i++){
        temp[i] = A[ind];
        ind--;
    }

    int lps[2*origLen+1];

    computeLPSArray(temp, 2*origLen+1, &lps);

    int res = lps[2*origLen]-origLen;
    res = abs(res);
    return res;
}

void main(){
    char A[] = "AACECAAAA";
    int res = solve(&A);

    printf("%d", res);
}

