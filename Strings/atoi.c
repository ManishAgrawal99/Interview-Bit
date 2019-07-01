/**
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9

Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

    Questions:

    Q1. Does string contain whitespace characters before the number?
    A. Yes

    Q2. Can the string have garbage characters after the number?
    A. Yes. Ignore it.

    Q3. If no numeric character is found before encountering garbage characters, what should I do?
    A. Return 0.

    Q4. What if the integer overflows?
    A. Return INT_MAX if the number is positive, INT_MIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.
**/

#include<stdio.h>
#include<conio.h>
#include<limits.h>


/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 *
 * @Output Integer
 */
int atoi(const char* A) {
    int neg = 0;
    long long int num = 0;
    int i,t;
    i=0;

    while(A[i]==' '){
        i++;
    }

    if(A[i]=='-'){
        neg=1;
        i++;
    }
    else if(A[i]=='+'){
        neg=0;
        i++;
    }

    while(A[i]>='0' && A[i]<='9'){
        t = A[i] - '0';
        num = num*10 + t;
        if(num>=INT_MAX){
            if(!neg){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }

        i++;
    }
    if(!neg){
        return num;
    }
    return num*-1;
}

void main(){
    char str[] = "5121478262 8070067M75 X199R 547 8C0A11 93I630 4P4071 029W433619 M3 5 14703818 776366059B9O43393";

    int res = atoi(&str);

    printf("%d", res);
}
