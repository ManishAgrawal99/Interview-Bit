/**
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

        A sequence of non-space characters constitutes a word.
        Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
        If there are multiple spaces between words, reduce them to a single space in the reversed string.
**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void reverseWords(char* s){
    int l = strlen(s);
    int flag=0,i=l-1,c=0;

    char*ans =(char*)malloc(sizeof(char)*l);

    while(i>=0){
        int j=i;
        if(s[i]>='A'){
            while(s[i]!= ' ' && i>=0)
                i--;

            int k;
            for(k= i+1;k<=j;k++)
                ans[c++]= s[k];
            if(i>=0)
            ans[c++]= ' ';
       }
       else
            i--;
    }

    for(i=0;i<c;i++)
        s[i]= ans[i];
    s[i]='\0';
}

void main(){
    char s[] = "the sky is blue";
    printf("%s\n", s);

    reverseWords(&s);
    printf("%s\n", s);


}
