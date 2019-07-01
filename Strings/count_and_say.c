/**


The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

**/

#include<stdio.h>
#include<conio.h>

char* countAndSay(int A) {
    int i=2,len=100000,j,k,count,z;
    char * res=(char *)malloc(len*sizeof(char));
    int * B=(int *)malloc(100000*sizeof(int));
    res[0]='1';
    res[1]='\0';
    while(i<=A){
        j=0,k=0;
        while(res[j])
        {
            count=1;
            while(res[j+1] && res[j]==res[j+1] )
            {
                j++;
                count++;
            }
            B[k++]=count;
            B[k++]=res[j]-'0';
            j++;
        }
        for(z=0;z<k;z++)
        {
            res[z]=B[z]+'0';
        }
        res[z]='\0';
        i++;
    }
    len=sizeof(res)+1;
    return res;
}

void main(){
    int B=5;

    char* res = countAndSay(B);

    int i = 0;
    while(res[i]!='\0'){
        printf("%c", res[i]);
        i++;
    }
}
