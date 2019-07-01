/**
You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.

Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.

Constraints

1 <= length(S) <= 1e6
S can have special characters

Example

Input
    ABEC

Output
    6

Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.
**/

#include<stdio.h>
#include<conio.h>

int solve(char* A) {
    int total = 0;
    int i=0;
    while(A[i]!='\0'){
        if(A[i]=='a' || A[i]=='A' ||  A[i]=='e' ||  A[i]=='E' ||  A[i]=='i' ||  A[i]=='I' ||  A[i]=='o' ||  A[i]=='O' ||  A[i]=='u' ||  A[i]=='U'){
            total = total + (strlen(A)-i);
            total = total % 10003;
        }
        i++;
    }
    return total;
}


void main(){
    char A[] = "ABEC";
    int res = solve(&A);

    printf("%d", res);
}
