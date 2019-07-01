/**
Compare two version numbers version1 and version2.

        If version1 > version2 return 1,
        If version1 < version2 return -1,
        otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int compareVersion(char* A, char* B) {

    int lenA = strlen(A);
    int lenB = strlen(B);

    char *ver1 = (char*) malloc (sizeof(char) * lenA);
    char *ver2 = (char*) malloc (sizeof(char) * lenB);

    unsigned long long int version1=0, version2=0;

    int i=0,j=0,k=0,Aperiod=0,Bperiod=0;


    while(Aperiod<lenA || Bperiod<lenB)
    {
        //For A
        i=Aperiod;
        k=0;

        while(i<lenA && A[i]=='0'){
            i++;
        }
        while(i<lenA && A[i]!='.'){
            ver1[k++]=A[i++];
            version1=10*version1+ A[i-1]-48;
        }
        ver1[k]='\0';
        Aperiod=i+1;


        //For B
        j=Bperiod;
        k=0;
        while(j<lenB && B[j]=='0' ){
            j++;
        }
        while(j<lenB && B[j]!='.'){
            ver2[k++]=B[j++];
            version2=10*version2 + B[j-1]-48;
        }
        ver2[k]='\0';
        Bperiod=j+1;


        //Compare
        if(version1>version2) return 1;
        else if(version2>version1) return -1;
        else{
            version1=0;
            version2=0;
        }
        //else if(Aperiod>=lenA && Bperiod<lenB) return -1;
        //else if(Aperiod<lenA && Bperiod>=lenB) return 1;
    }
    return 0;
}

void main(){
    char A[] = "1.0.0";
    char B[] = "01";

    int res = compareVersion(&A,&B);

    printf("%d", res);
}
