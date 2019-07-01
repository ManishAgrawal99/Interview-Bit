/**
Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)

Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1
**/

#include<stdio.h>
#include<conio.h>
#include<string.h>


/**
int power(char* A) {
    unsigned long long int num=0;
    int i=0;

        while(A[i]!='\0')
        {
            num = 10*num + (A[i++]-'0');
        }
    if(num == 1){
     return 0;
    }
    return !(num & (num-1) );
}
**/

int isPowerOf2(char* str)
{
    int i,j;
    int len_str = strlen(str);

    int num = 0;

    if (len_str == 1 && str[len_str - 1] == '1')
        return 0;

    while (len_str != 1 || str[len_str - 1] != '1') {

        if ((str[len_str - 1] - '0') % 2 == 1)
            return 0;

        for (i = 0, j = 0; i < len_str; i++) {
            num = num * 10 + str[i] - '0';

            // if num < 2 then we have to take another digit
            // to the right of A[i] to make it bigger than
            // A[i]. E. g. 214 / 2 --> 107
            if (num < 2) {

                // if it's not the first index. E.g 214
                // then we have to include 0.
                if (i != 0)
                    str[j++] = '0';

                // for eg. "124" we will not write 064
                // so if it is the first index just ignore
                continue;
            }

            str[j++] = (int)(num / 2) + '0';
            num = (num) - (num / 2) * 2;
        }

        str[j] = '\0';

        // After every division by 2 the
        // length of string is changed.
        len_str = j;
    }

    // if the string reaches to 1 then the str is
    // a power of 2.
    return 1;
}

int power(char* A) {
    return isPowerOf2(A);
}

void main(){
    char num[] = "51539607552";

    if(power(&num)){
        printf("power of 2");
    }
    else{
        printf("NOT a power of 2");
    }
}
