#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4;

    /*
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    n=3;
    */

    /*
    int A[2][2] = {
        {1, 2},
        {4, 5}
    };
    */


    int cycles = (n/2);

    int i,j,temp;

    printf("\nBefore Rotation\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for(i=0; i<cycles; i++){
        for(j=i;j<n-1-i;j++){
            temp = A[i][j];
            A[i][j] = A[n-1-j][i]; //TL
            A[n-1-j][i] = A[n-1-i][n-1-j];  //BL
            A[n-1-i][n-1-j] = A[j][n-1-i];  //BR
            A[j][n-1-i] = temp;   //TR
        }
    }

    printf("\nAfter Rotation\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

}
