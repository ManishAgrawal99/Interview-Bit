#include<stdio.h>
#include<conio.h>

/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
**/

int* maxset(int* A, int n1, int *length_of_array) {
    *length_of_array = n1;
    int * ret = (int *) malloc(sizeof(int) * *length_of_array);

    long long sum = 0, maxSum = 0, count = 0, maxCount = 0, i = -1, startIdx = 0;

    while(i < n1)
    {
        i++;
        startIdx = i;
        sum = 0;
        count = 0;
        while(i < n1 && A[i] >= 0)
        {
            sum += (long long)A[i++];
            count++;
        }
        if (sum > maxSum || (sum == maxSum && count > maxCount))
        {
            maxSum = sum;
            maxCount = count;
            memcpy(ret, A + startIdx, sizeof(int) * maxCount);
        }

    }

     *length_of_array = maxCount;
      return ret;
}


void main(){

    int i,n;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);

    int* A = (int* )malloc(sizeof(int)*n);

    printf("Enter the elements in the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    int length_of_array;

    int* B = maxset(A, n, &length_of_array);

    printf("\n");
    for(i=0;i<length_of_array;i++){
        printf("%d ", B[i]);
    }
}
