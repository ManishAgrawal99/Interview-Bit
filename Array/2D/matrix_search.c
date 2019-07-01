/**


Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than or equal to the last integer of the previous row.

Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

**/

#include<stdio.h>
#include<conio.h>

int searchMatrix(int** A, int n11, int n12, int B) {
    int i,j;
    int min = 0;
    int max = (n11*n12)-1;
    int mid = min + (max-min)/2;

    int tmin = A[0][0];
    int tmax = A[n11-1][n12-1];
    int tmid = A[mid/n12][mid%n12];

    while(min<=max){
        mid = min + (max-min)/2;
        tmid = A[mid/n12][mid%n12];

        if(tmid == B){
            return 1;
        }
        else if(tmid < B){
            min = mid+1;
        }
        else{
            max = mid-1;
        }
    }
    return 0;
}



void main(){

    int i,j;
    int n11, n12;
    int B;

    printf("Enter the number of rows and columns :");
    scanf("%d %d", &n11, &n12);

    int **A = (int **)malloc(n11 * sizeof(int *));
    for(i=0;i<n11;i++)
        *(A+i) = (int*)malloc(n12 * sizeof(int));

    printf("Enter the matrix: \n");
    for(i=0;i<n11;i++){
        for(j=0;j<n12;j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter the number to search: ");
    scanf("%d", &B);

    int res = searchMatrix(A, n11, n12, B);
    if(res){
        printf("Found");
    }
    else{
        printf("Not Found");
    }
}
