#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

int int_cmp(const void *a, const void *b) {
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}

int threeSumClosest(int* A, int n1, int B) {
    qsort(A, n1, sizeof(int), int_cmp);

    int i,j,k;
    long long int sum, res;
    int dif = INT_MAX;

    for(i=0;i<n1-2;i++){
        j = i+1;
        k = n1-1;

        while(k>j){
            sum = A[i] + A[j] + A[k];
            if(abs(sum-B)<dif){
                dif = abs(sum-B);
                res = sum;
            }

            if(sum==B){
                return B;
            }

            if(sum>B){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return res;
}

void main(){
    int A[] = {-1, 2, 1, -4};
    int n = sizeof(A)/sizeof(A[0]);
    int B = 1;

    int res = threeSumClosest(&A, n, B);

    printf("%d", res);
}
