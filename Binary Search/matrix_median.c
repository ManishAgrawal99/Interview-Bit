/**
Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.


**/

#include<stdio.h>
#include<conio.h>
#include<limits.h>

int LessNum(int* A, const int num, int n12) {
    const int N = n12;
    int lo = 0, hi = N - 1;

    while (lo < hi) {
        int m = lo + (hi - lo) / 2;

        if (A[m] >= num) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }

    return (A[lo] >= num) ? lo : N;
}

int LessNums(int** A, const int num, int n11, int n12) {
    const int M = n11;

    int ans = 0;
    int i;

    for (i = 0; i < M; i++) {
        ans += LessNum(A[i], num, n12);
    }

    return ans;
}

int findMedian(int** A, int n11, int n12) {

    const int M = n11;
    const int N = n12;
    const int target_index = (M * N) / 2;

    int lo = 0, hi = INT_MAX - 1;
    int m, lessnums;

    while (lo < hi) {
        m = lo + (hi - lo + 1) / 2;

        lessnums = LessNums(A, m, n11, n12);
        if (lessnums <= target_index) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }

    return lo;
}

void main(){

    int n11;
    int n12;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n11, &n12);

    int i,j;
    int **A = (int **)malloc(3 * sizeof(int *));
    for(i=0;i<3;i++)
        *(A+i) = (int*)malloc(3 * sizeof(int));

    printf("Enter the matrix:\n");
    for(i=0;i<n11;i++){
        for(j=0;j<n12;j++){
            scanf("%d", &A[i][j]);
        }
    }

    int median = findMedian(A, n11, n12);

    printf("%d", median);
}
