/**
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input :
Array = {1 1 0 1 1 0 0 1 1 1 }
M = 1

Output :
[0, 1, 2, 3, 4]


**/

#include<stdio.h>
#include<conio.h>

int* maxone(int* A, int n1, int B, int *len1) {
    *len1=n1;
    int *res=(int *)malloc(*len1 * sizeof(int));
    int left=0,right=0,maxdiff=-1,zeros=0,best_r,best_l,i,j=0;
    while(right<n1)
    {
        if(zeros<=B)
        {
            if(A[right]==0)
            zeros++;
            right++;
        }
        if(zeros>B)
        {
            if(A[left]==0)
            zeros--;
            left++;
        }
        if(right-left>maxdiff)
        {
            maxdiff=right-left;
            best_r=right-1;
            best_l=left;
        }
    }
    for(i=best_l;i<=best_r;i++)
    res[j++]=i;
    *len1=best_r-best_l+1;
    return res;
}

void main(){
    int A[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    int n = sizeof(A)/sizeof(A[0]);

    int B = 2;

    int len1;

    int* res = maxone(&A, n, B, &len1);

    int i;
    for(i=0;i<len1;i++){
        printf("%d ", res[i]);
    }
}

/**

int* maxone(int* A, int n1, int B, int *len1) {
    int max=0,temp=0,firstZero=-1;
    int i=0;
    int M=B;
    int start,end,tstart=0,tend=-1;
    int ind=0;

    if(B==0){
        for(i=0;i<n1;i++){
            if(A[i]==1){
                temp++;
                tend++;
            }
            if(A[i]==0){
                if(temp>max){
                    max=temp;
                    start = tstart;
                    end=tend;
                }
                tstart = i+1;
                tend=i;
                temp=0;
            }
        }

        if(tend-tstart+1 > max){
        max = tend-tstart+1;
        start = tstart;
        end = tend;
        }

        int* res = (int*)malloc(sizeof(int)*max);
        for(i=start;i<=end;i++){
            res[ind] = i;
            ind++;
        }
        *len1 = max;
        return res;

    }

    while(i<n1){
        if(A[i]==1){
            tend++;
            i++;
        }
        else if(A[i]==0 && M>0){
            tend++;
            M--;
            if(firstZero==-1){
                firstZero = i;
            }
            i++;
        }
        else if(A[i]==0 && M==0){
            if(tend-tstart+1 > max){
                max = tend-tstart+1;
                start = tstart;
                end = tend;
            }
            if(B==0){
                i=firstZero+2;
                M=B;
                tstart = i;
                tend = i-1;
                firstZero = -1;
            }
            else{
                i=firstZero+1;
                M=B;
                tstart = i;
                tend = i-1;
                firstZero=-1;
            }
        }
    }
    if(tend-tstart+1 > max){
        max = tend-tstart+1;
        start = tstart;
        end = tend;
    }

    int* res = (int*)malloc(sizeof(int)*max);
    for(i=start;i<=end;i++){
        res[ind] = i;
        ind++;
    }
    *len1 = max;
    return res;



}

**/
