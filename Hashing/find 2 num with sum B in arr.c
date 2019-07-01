/**


Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2.
Please note that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ).
Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum.
If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2


**/

#include<stdio.h>
#include<conio.h>

int* twoSum(const int* a, int n, int b, int *len) {
   int i,j ;
    for(j=1;j<n;j++)
    {
        for(i=0;i<j;i++)
        {
            if ((a[i]+a[j])==b)
            break ;
        }
        if (i!=j)
        break ;
    }
    if (j==n)
    {
       *len = 0 ;
       return NULL ;
    }
    else
    {
        *len= 2 ;
        int * res = malloc(sizeof(int)*2);
        res[0]= i+1 ;
        res[1] = j+1 ;
        return res ;
    }
}

void main(){
    int A[] = {2,7,11,15};

    int len1;
    int B = 9;

    int n = sizeof(A)/sizeof(A[0]);

    int* res = twoSum(A,n,B,&len1);

    printf("%d ", res[0]);
    printf("%d ", res[1]);
}
