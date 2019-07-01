/**
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14

Input : "XX"
Output : 20


**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int romanToInt(char* A) {
    int i=0;
    int num = 0;
    char c;

    // I = 1
    // V = 5
    // X = 10
    // L = 50
    // C = 100
    // D = 500
    // M = 1000

    for(i=0;i<strlen(A);i++){
        c = A[i];

        if(c=='I'){
            num++;
        }
        else if(c=='V'){
            num+=5;
            if(i!=0){
                if(A[i-1]=='I'){
                    num-=2;
                }
            }
        }
        else if(c=='X'){
            num+=10;
            if(i!=0){
                if(A[i-1]=='I'){
                    num-=2;
                }
            }
        }
        else if(c=='L'){
            num+=50;
            if(i!=0){
                if(A[i-1]=='X'){
                    num-=20;
                }
            }
        }
        else if(c=='C'){
            num+=100;
            if(i!=0){
                if(A[i-1]=='X'){
                    num-=20;
                }
            }
        }
        else if(c=='D'){
            num+=500;
            if(i!=0){
                if(A[i-1]=='C'){
                    num-=200;
                }
            }
        }
        else if(c == 'M'){
            num+=1000;
            if(i!=0){
                if(A[i-1]=='C'){
                    num-=200;
                }
            }
        }
    }

    return num;
}

void main(){
    char roman[] = "MMXIX";
    int num = romanToInt(&roman);

    printf("%d", num);
}
