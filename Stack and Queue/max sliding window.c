/**
A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. You have to find the maximum for each window. The following example will give you more clarity.

Example :

The array is [1 3 -1 -3 5 3 6 7], and w is 3.
Window position 	    Max

[1 3 -1] -3 5 3 6 7 	3
1 [3 -1 -3] 5 3 6 7 	3
1 3 [-1 -3 5] 3 6 7 	5
1 3 -1 [-3 5 3] 6 7 	5
1 3 -1 -3 [5 3 6] 7 	6
1 3 -1 -3 5 [3 6 7] 	7

Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

Note: If w > length of the array, return 1 element with the max of the array.


**/

#include<stdio.h>
#include<conio.h>

int findmax(const int* A, int n){
    int i,max=A[0];
    for(i=1;i<n;i++)
        max=max<A[i]?A[i]:max;
    return max;
 }

int* slidingMaximum(const int* A, int n1, int B, int *len1) {
    *len1=n1-B+1;
    int* res = (int*)malloc(sizeof(int)* (n1-B+1));

    if(B>=n1){
        res[0] = findmax(A,n1);
        return res;
    }

    int i,max=findmax(A,B);

    for(i=0;i+B-1<n1;i++){
        res[i] = max;
        if(max<A[i+B])
            max=A[i+B];
        else if(max==A[i])
            max=findmax(A+i+1,B);
    }
    return res;
}

void main(){
    int A[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(A)/sizeof(A[0]);

    ///Window size
    int B=3;

    int len1 = 0;
    int* res = slidingMaximum(A, n, B, &len1);

    int i;
    for(i=0;i<len1;i++){
        printf("%d ", res[i]);
    }
}
