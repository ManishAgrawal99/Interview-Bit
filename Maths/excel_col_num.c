/**
Given a column title as appears in an Excel sheet, return its corresponding column number.

A -> 1

    B -> 2

    C -> 3

    ...

    Z -> 26

    AA -> 27

    AB -> 28
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

int titleToNumber(char* A)
{
    int i, ans = 0, size = 0, power;
    for(i = 0; A[i] != '\0'; i++)
    {
        size++;
    }
    for(i = 0; i < size; i++)
    {
        power = size - i - 1;
        ans += pow(26, power) * (A[i] - 64);
    }
    return ans;
}

void main(){
    char c[10];
    printf("Enter the column name: ");
    scanf("%s", &c);

    int col_num = titleToNumber(c);
    printf("%d", col_num);
}
