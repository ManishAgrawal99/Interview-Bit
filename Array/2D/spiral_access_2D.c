#include<stdio.h>
#include<conio.h>

void main(){

    int m, n, i, j;
    int T, B, L, R;
    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &m, &n);
    int A[m][n];

    printf("Enter the array:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("The entered array is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    T=0;
    B=m-1;
    L=0;
    R=n-1;
    int dir=0;
    while(T<=B && L<=R){
        if(dir==0){
            for(i=L;i<=R;i++){
                printf("%d ", A[T][i]);
            }
            T++;
            dir=1;
        }
        if(dir==1){
            for(i=T;i<=B;i++){
                printf("%d ", A[i][R]);
            }
            R--;
            dir=2;
        }
        if(dir==2){
            for(i=R;i>=L;i--){
                printf("%d ", A[B][i]);
            }
            B--;
            dir=3;
        }
        if(dir==3){
            for(i=B;i>=T;i--){
                printf("%d ", A[i][L]);
            }
            L++;
            dir=0;
        }


    }
}
