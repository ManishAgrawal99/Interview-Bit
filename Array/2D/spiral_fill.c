/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order
Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]


*/

#include<stdio.h>
#include<conio.h>

void main(){
    int n;
    int i,j,x,d,l,r,t,b;

    printf("Enter the number of rows and columns of square matrix: ");
    scanf("%d", &n);

    //Creating a 2D array of size n*n;
    int **result = (int **)malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
        *(result+i) = (int*)malloc(n * sizeof(int));

    x=1;
    d=0;
    l=0;
    r=n-1;
    t=0;
    b=n-1;

    while(l<=r&&t<=b){
        if(d%4==0){
            for(i=l;i<=r;i++){
                result[t][i]=x;
                x++;
            }
            t++;
        }
        if(d%4==1){
            for(i=t;i<=b;i++){
                result[i][r]=x;
                x++;
            }
            r--;
        }
        if(d%4==2){
            for(i=r;i>=l;i--){
                result[b][i]=x;
                x++;
            }
            b--;
        }
        if(d%4==3){
            for(i=b;i>=t;i--){
                result[i][l]=x;
                x++;
            }
            l++;
        }
        d++;
    }

    printf("The spiraled array is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
