/**


Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB


**/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char* convertToTitle(int A) {
	// SAMPLE CODE
	/*
	 * char *result = (char *)malloc(100 * sizeof(char));
	 * // DO STUFF
	 * return result;
	 */
	 int rem,i=0,j;
	 char *result = (char *)malloc(100 * sizeof(char));
	 while(A>0)
	 {
	     rem=A%26;
	     A=A/26;
	     if(rem==0)
	     {
	         A--;
	         rem=90;
	     }
	     else
	     rem=rem+64;
	     result[i++]=rem;
	 }
	 result[i]='\0';

	 for(j=0;j<i/2;j++)
	 {
	     char b=result[j];
	     result[j]=result[i-1-j];
	     result[i-1-j]=b;
	 }
	 return result;
}


void main(){
    char *res = (char *)malloc(100 * sizeof(char));
    int A = 28;
    int i = 0;

    res = convertToTitle(A);
    printf("%s", res);


}
