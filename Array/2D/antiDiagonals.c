/**
 * Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

 Input:

1 2 3
4 5 6
7 8 9

Return the following :

[
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
 */
 #include<stdio.h>
 #include<conio.h>

void main(){
    int n11;
    int i,j,k,count;
    int number = 1;

    printf("Enter the num of rows and cols: ");
    scanf("%d", &n11);

    int A[n11][n11];
    for(i=0;i<n11;i++){
        for(j=0;j<n11;j++){
            A[i][j] = number;
            number++;
        }
    }

    int n=n11;

    int result[2*n-1][n];
    for(i=0;i<2*n-1;i++){
        for(j=0;j<n;j++){
            result[i][j] = 0;
        }
    }

    for(k=0; k<n11; k++){
        j=k;
        i=0;
        count=0;
        while(i<n11&&j>=0){
            result[k][count] = A[i][j];
            count++;
            i++;
            j--;
        }
    }
    int l=k;
    for(k=1;k<n11;k++){
        i=k;
        j=n11-1;
        count = 0;
        while(i<n11&&j>=0){
            result[l][count] = A[i][j];
            count++;
            i++;
            j--;
        }
        l++;
    }


    printf("\n");
    for(i=0;i<2*n-1;i++){
        for(j=0;j<n;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}
