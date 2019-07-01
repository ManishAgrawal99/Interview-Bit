/**
Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"


**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

char num_to_char(int num) {
    switch (num) {
        case 1: return 'I';
        case 5: return 'V';
        case 10: return 'X';
        case 50: return 'L';
        case 100: return 'C';
        case 500: return 'D';
        case 1000: return 'M';
    }
}

int corresponding_level(int num) {
    switch (num) {
        case 1: return 0;
        case 5: return 1;
        case 10: return 1;
        case 50: return 10;
        case 100: return 10;
        case 500: return 100;
        case 1000: return 100;
    }
}

int next_level(int num) {
    switch (num) {
        case 1: return 0;
        case 5: return 1;
        case 10: return 5;
        case 50: return 10;
        case 100: return 50;
        case 500: return 100;
        case 1000: return 500;
    }
}

char* intToRoman(int A) {
    int level = 1000;
    char *res = NULL;
    int j = 0;
    res = (char*)malloc(20*sizeof(char));

    while (A > 0) {
        while (A >= level) {
            res[j++] = num_to_char(level);
            A -= level;
        }
        if (A >= (level - corresponding_level(level))) {
            res[j++] = num_to_char(corresponding_level(level));
            res[j++] = num_to_char(level);
            A -= level - corresponding_level(level);
            level = corresponding_level(level);
        } else {
            level = next_level(level);
        }
    }

    res[j] = '\0';
    return res;
}

void main(){
    int num = 2019;

    char* res = (char*)malloc(sizeof(char)* 50);

    res = intToRoman(num);

    printf("%s", res);

}
