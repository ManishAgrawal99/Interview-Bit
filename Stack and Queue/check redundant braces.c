/**
Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0
**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int braces(char* A) {

    int n = strlen(A);
    int i;

    int top = -1;
    char stack[n+1];

    for(i=0;i<n;i++){
        if(A[i] == '(' || A[i]=='+' || A[i]=='-' || A[i]=='/' || A[i]=='*'){
            top++;
            stack[top] = A[i];
        }
        else if(A[i] == ')'){
            if(top>=1){
                if((stack[top]=='+' || stack[top]=='-' || stack[top]=='/' || stack[top]=='*')&& stack[top-1]=='('){
                    top = top-2;
                }
                else{
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

void main(){
    char expression[100];

    printf("Enter the expression: ");
    gets(expression);

    int res = braces(&expression);

    if(res){
        printf("\nRedundant Braces");
    }
    else{
        printf("\nNO Redundant Braces");
    }
}
