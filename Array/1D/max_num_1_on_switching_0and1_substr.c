/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN.
In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR.
By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.
If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R.
If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

    Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.


If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].
*/


#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(){
    char arr[100];
    printf("Enter a string of 0 and 1: ");
    scanf("%s",&arr);

    int len = strlen(arr);
    int i;
    int tempStart=0;
    int start = -1;
    int tempEnd = 0;
    int end=-1;
    int sum=0;
    int finalSum = 0;

    for(i=0;i<len;i++){
        if(arr[i] == '0'){
            sum++;
        }
        else{
            sum--;
        }

        if(sum<0){
            sum=0;
            tempStart = i+1;
        }
        if(sum>finalSum){
            finalSum = sum;
            start = tempStart;
            end = i;
        }
    }

    printf("\n\nThe flips must start from %d and end at %d", start, end);
}
