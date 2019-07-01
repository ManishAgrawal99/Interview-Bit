/**
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

    Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
    Example : itertools.combinations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points.
**/


#include<stdio.h>
#include<conio.h>


int prepare(int n, int k, int *data, int dindex, int curn, int **result, int rindex) {
    if(dindex == k) {
        // all elements filled
        int i;
        for(i=0; i<dindex; i++)
            result[rindex][i] = data[i];
        return rindex+1;
    } else {
        if(curn <= n) {
            data[dindex] = curn;
            rindex = prepare(n, k, data, dindex+1, curn+1, result, rindex);
            rindex = prepare(n, k, data, dindex, curn+1, result, rindex);
        }
        return rindex;
    }
}

int ** combine(int n, int k, int *len1, int *len2) {
    long prod = 1;
    int i;
    for(i=n-k+1; i<=n; i++)
        prod *= ((long)i);

    long prod2 = 1;
    for(i=1; i<=k; i++)
        prod2 *= ((long)i);

    *len1 = (int)(prod/prod2);
    *len2 = k;

    int **result = (int **)malloc(*len1 * sizeof(int *));
    for(i=0; i<(*len1); i++)
        result[i] = (int *)malloc(k * sizeof(int));

    int *data = (int *)malloc(k * sizeof(int));
    prepare(n, k, data, 0, 1, result, 0);
    free(data);

    return result;
}

void main(){
    int n = 4;
    int k = 2;

    int len1, len2, i, j;

    int** res = combine(n,k, &len1, &len2);

    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

}
