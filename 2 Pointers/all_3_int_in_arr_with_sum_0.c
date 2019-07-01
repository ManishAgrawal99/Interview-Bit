/**


Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}


//int ** threeSum(int* A, int n1, int *len1, int *len2) {
void threeSum(int* A, int n1) {

    int **B,i=0,j,k,temp;

    B=malloc(((n1*(n1-1))/2)*sizeof(int *));

    //*len1=0;
    //All *len1 converted to len1
    int len1 = 0;

    qsort(A,n1,sizeof(int),compare);

    while(i<n1 && A[i]<=0){
        j=i+1;
        k=n1-1;
        while(j<k){
            if(A[i]+A[j]+A[k]>0)
                k--;
            else if(A[i]+A[j]+A[k]<0)
                j++;
            else{
                B[len1]=malloc(3*sizeof(int));
                B[len1][0]=A[i];
                B[len1][1]=A[j];
                B[len1][2]=A[k];
                (len1)++;
                temp=A[j];
                while(j<n1 && A[j]==temp)
                    j++;
            }
        }
        temp=A[i];
        while(i<n1 && A[i]==temp)
            i++;
    }
    //*len2=3;
    //return B;

    for(i=0;i<len1;i++){
        for(j=0;j<3;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int A[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(A)/sizeof(A[0]);

    threeSum(&A, n);
}
