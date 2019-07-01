/**
*Validate if a given string is numeric.

Examples:

    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


        Is 1u ( which may be a representation for unsigned integers valid?
        For this problem, no.

        Is 0.1e10 valid?
        Yes

        -01.1e-10?
        Yes

        Hexadecimal numbers like 0xFF?
        Not for the purpose of this problem

        3. (. not followed by a digit)?
        No

        Can exponent have decimal numbers? 3e0.1?
        Not for this problem.

        Is 1f ( floating point number with f as prefix ) valid?
        Not for this problem.

        How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
        Not for this problem.

        How about integers preceded by 00 or 0? like 008?
        Yes for this problem


**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int isNumber(const char* A) {
    char c;
    int len = strlen(A);
    int i = 0;
    int decimal = 0;
    int expo = 0;
    int space = 0;

    while (A[i] == ' ' && i < len){
        i++;
    }

    if (A[i] == '-' || A[i] == '+'){
        i++;
    }

    if (A[i] == '.'){
        decimal == 1;
        i++;
    }

    if (!isdigit(A[i])){
        return 0;
    }

    while (i < len){
        if (space == 1 && A[i] != ' ')
             return 0;

        if (A[i - 1] == '.' && !isdigit(A[i]))
            return 0;

        if (A[i] == '-' && A[i - 1] == 'e'){
            i++;
            continue;
        }

        if (!isdigit(A[i])){
            if (A[i] == ' '){
                space = 1;
                i++;
                continue;
            }

            if (A[i] == '.'){
                if (expo == 1)
                     return 0;
                if (decimal == 1)
                    return 0;
                decimal = 1;
                i++;
                continue;
            }

            if (A[i] == 'e'){
                if (expo == 1)
                    return 0;
                expo = 1;
                i++;
                continue;
            }

            return 0;
        }

        i++;
    }

    if (A[i-1] == '.')
        return 0;
    return 1;
}

void main(){
    char str[] = "2e10";

    int isnum = isNumber(&str);

    if(isnum){
        printf("Number");
    }
    else{
        printf("Not a Number");
    }
}
