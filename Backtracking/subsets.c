/**


Given a set of distinct integers, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        Also, the subsets should be sorted in ascending ( lexicographic ) order.
        The list is not necessarily sorted.

Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]


**/

#include<stdio.h>
#include<conio.h>

void merge(int* a,int left,int mid,int right)
{
    int u=mid-left+1;
    int y=right-mid;
    int b[u];
    int c[y];
    int i=0;
    int j=0;
    for(i=0;i<u;i++)
    {
        b[i]=a[left+i];
    }
    for(j=0;j<y;j++)
    {
        c[j]=a[mid+1+j];
    }
     i=0;
    j=0;
    int k=left;
    while((i<u)&&(j<y))
    {
        if(b[i]<c[j])
        {
            a[k]=b[i];
            i++;
            k++;
        }
        else
        {
            a[k]=c[j];
            j++;
            k++;
        }
    }
    int q=0;
    if(i<u)
    {
        for(q=i;q<u;q++)
        {
            a[k]=b[q];
            k++;
        }
    }
    else
    {
        for(q=j;q<y;q++)
        {
            a[k]=c[q];
            k++;
        }
    }
}

void mergesort(int* a,int left,int right){
    if(left<right)
    {
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);

        merge(a,left,mid,right);
    }
    else return ;
}

void traverse(int* a, int* b,int index,int n,int* c,int j){
    if(index==n)
    {
        return ;
    }
    else
    {
        int i=j;
        for(i=j;i<n;i++)
        {
            if(c[i]==1)
            {
                continue;
            }
            else
            {
            b[index]=a[i];
            c[i]=1;
            //index[0]=index[0]+1;
            printf("[");
            int k=0;
            for(k=0;k<=index;k++)
            {
                printf("%d ",b[k]);
            }
            printf("] ");
            traverse(a,b,index+1,n,c,i+1);
            c[i]=0;
            }
        }
    }
}
int ** subsets(int* a, int n, int *len1, int *len2) {
    mergesort(a,0,n-1);
    int* b=(int*)malloc(n*sizeof(int));
    int* c=(int*)malloc(n*sizeof(int));
    int i=0;
    int j=0;
    printf("[] ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[j]=0;
        }
        b[0]=a[i];
        printf("[");
        printf("%d ] ",b[0]);
        c[i]=1;
        traverse(a,b,1,n,c,i+1);
        c[i]=0;
    }
    *len1=0;
    *len2=0;
    int** d=(int**)malloc(0*sizeof(int*));
    return d;
}


void main(){
    int A[] = {1,2,3};
    int n = sizeof(A)/sizeof(A[0]);

    int len1, len2, i, j;

    int** res = subsets(A, n, &len1, &len2);
}
