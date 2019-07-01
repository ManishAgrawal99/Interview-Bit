/**
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"

Return a + b = “111”.

**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

char* addBinary(char* A, char* B) {
    int n=strlen(A);
    int m=strlen(B);

    int c=0,i,j,sum=0;

    for(i=0;i<n;i++)
        A[i]=A[i]-'0';

    for(i=0;i<m;i++)
        B[i]=B[i]-'0';

    if(n<m){
        for(i=m-1,j=n-1;i>=m-n;i--,j--){
            sum=(A[j]+B[i]+c)%2;
            c=(A[j]+B[i]+c)/2;
            B[i]=sum+'0';
        }

        for(;i>=0;i--){
            sum=(B[i]+c)%2;
            c=(B[i]+c)/2;
            B[i]=sum+'0';
        }
        if(c==0)
        return B;
        else{
            char *s=malloc((m+1)*sizeof(char));
            s[0]=c+'0';
            for(i=1;i<=m;i++)
            s[i]=B[i-1];
            return s;
        }
    }

    if(n>=m){
        for(i=n-1,j=m-1;i>=n-m;i--,j--){
            sum=(A[i]+B[j]+c)%2;
            c=(A[i]+B[j]+c)/2;
            A[i]=sum+'0';
        }

        for(;i>=0;i--){
            sum=(A[i]+c)%2;
            c=(A[i]+c)/2;
            A[i]=sum+'0';
        }
        if(c==0)
            return A;
        else{
            char *s=malloc((n+1)*sizeof(char));
            s[0]=c+'0';
            for(i=1;i<=n;i++)
            s[i]=A[i-1];
            return s;
        }

    }
}

void main(){
    char arr1[] = "1000";
    char arr2[] = "111";

    char* res = addBinary(&arr1, &arr2);

    printf("%s", res);
}
