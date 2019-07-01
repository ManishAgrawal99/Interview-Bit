/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

In case of duplicates, we can find the pivot in O(n) by traversing the array
After that the arr is divided into 2 sorted arrays
we can search the number in 2 separately

**/


#include<stdio.h>
#include<conio.h>

int search(const int* A, int n1, int B) {
    int low = 0;
    int high = n1-1;
    int mid;

    while(low<=high){
        mid = low + (high-low)/2;
        if(A[mid] == B){
            return mid;
        }
        else if(A[0]<=A[mid]){       //i.e. left part is sorted
            if(A[0]<=B && B < A[mid]){
                 high = mid-1;    //B lies on left part
            }
            else{
                low = mid+1;
            }
        }
        else{         //right part is sorted
            if(A[mid] < B && B<=A[n1-1]){
                low = mid+1;   //B lies on right part
            }
            else{
                 high = mid-1;
            }
        }
    }
    return -1;

}

void main(){
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(A)/sizeof(A[0]);
    int B = 0;

    int pos = search(&A, n, B);

    printf("%d", pos);
}
