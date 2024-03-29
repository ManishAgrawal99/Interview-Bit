/**
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;

Example :

Input :
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5
         With 10 from A, 15 from B and 10 from C.
**/

#include<stdio.h>
#include<conio.h>
#include<limits.h>

int maxof(int a,int b,int c)
{
    int x=(a>b)?a:b;
    int y=(x>c)?x:c;
    return y;
}
int minof(int a,int b,int c)
{
    int x=(a<b)?a:b;
    int y=(x<c)?x:c;
    return y;
}
int minimize(const int* A, int n1, const int* B, int n2, const int* C, int n3) {
    int i=0,j=0,k=0,max,min,res=INT_MAX;
    while(i<n1 && j<n2 && k<n3)
    {
        max=maxof(A[i],B[j],C[k]);
        min=minof(A[i],B[j],C[k]);
        res=((max-min)<res)?max-min:res;
        if(min==A[i])       i++;
        else if(min==B[j])  j++;
        else                k++;
    }
    return res;
}

void main(){
    int A[] = {1, 4, 10};
    int B[] = {2, 15, 20};
    int C[] = {10, 12};

    int n1 = sizeof(A)/sizeof(A[0]);
    int n2 = sizeof(B)/sizeof(B[0]);
    int n3 = sizeof(C)/sizeof(C[0]);

    int res = minimize(&A, n1, &B, n2, &C, n3);

    printf("%d", res);
}
