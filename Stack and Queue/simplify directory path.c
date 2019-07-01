/**
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

**/


#include<stdio.h>
#include<conio.h>
#include<string.h>

char* simplifyPath(char* A) {
    int n=strlen(A);
    char *s=(char*)malloc(sizeof(char)*(n+1));
    int top=-1,i;
    int dot=0;
    for(i=0;i<n;i++)
    {
        if(A[i]=='.')
        {
            dot++;
        }
        else
        {
            if(dot==1)
            {
                dot=0;
            }
            if(dot==2)
            {
                top--;
                while(s[top]!='/' && top>0)
                    top--;
                dot=0;
            }
            if(dot>2)
            {
                while(dot)
                {   dot--;
                    s[++top]='.';
                }
            }
            if(top>=0 && A[i]=='/' && s[top]=='/')
                continue;
            s[++top]=A[i];
        }
    }
    if(dot==1)
            {
                dot=0;
            }
            if(dot==2)
            {
                top--;
                while(s[top]!='/')
                    top--;
                dot=0;
            }
            if(dot>2)
            {
                while(dot)
                {   dot--;
                    s[++top]='.';
                }
            }
    if(s[top]=='/' && top>0)
        s[top]='\0';
    else if(top>=0)
        s[++top]='\0';
    else if(top<0)
    {
        s[++top]='/';
        s[++top]='\0';
    }
    return s;
}

void main(){
    char path[100];

    printf("Enter the directory path: ");
    gets(path);

    char* res = simplifyPath(&path);
    printf("%s", res);
}
