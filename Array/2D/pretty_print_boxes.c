/**
Print concentric rectangular pattern in a 2d matrix.
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

Example 2:

Input: A = 3.
Output:

3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3


**/

#include<stdio.h>
#include<conio.h>

int ** prettyPrint(int A) {
    int n = 2*A - 1;
    int i;

    int **res = (int **)malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
        *(res+i) = (int*)malloc(n * sizeof(int));

    int T=0;
    int B=n-1;
    int L=0;
    int R=n-1;
    int dir=0;
    int num = A;


    while(T<=B && L<=R){
        if(dir==0){
            for(i=L;i<=R;i++){
                res[T][i] = num;
            }
            T++;
            dir=1;
        }
        if(dir==1){
            for(i=T;i<=B;i++){
                res[i][R] = num;
            }
            R--;
            dir=2;
        }
        if(dir==2){
            for(i=R;i>=L;i--){
                res[B][i] = num;
            }
            B--;
            dir=3;
        }
        if(dir==3){
            for(i=B;i>=T;i--){
                res[i][L] = num;
            }
            L++;
            num--;
            dir=0;
        }
    }

    return res;
}

void main(){
    int A = 5;
    int n = 2*A - 1;

    int **res = prettyPrint(A);

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
