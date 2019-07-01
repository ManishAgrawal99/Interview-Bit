/**


Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

**/

#include<stdio.h>
#include<conio.h>

int* searchRange(const int* A, int n1, int B) {
    int *result = (int *)malloc(2*sizeof(int));
    int low=0,high=n1-1,mid;
    result[0] = -1;
    result[1] = -1;


    while(low <= high)
    {
        mid = (low+high)/2;
        if(A[mid] == B)
        {
            result[0] = mid;
            high = mid-1;
        }
        else if(A[mid]<B)
        low = mid+1;
        else
        high =  mid-1;
    }


    low = 0;high = n1-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(A[mid] == B)
        {
            result[1] = mid;
            low = mid+1;
        }
        else if(A[mid]<B)
        low = mid+1;
        else
        high = mid-1;
    }

    return result;
}


void main(){
    const int A[] = {1,1,1,2,3,3,3,3,4,4,5,6,7,8,8,8,8,9,9,9};
    int n1 = 20;
    int search = 1;

    //int *range = (int *)malloc(2*sizeof(int));

    int* range = searchRange(A, n1, search);

    printf("%d %d", range[0], range[1]);
}
