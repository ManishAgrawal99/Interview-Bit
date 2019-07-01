/**


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0


**/

#include<stdio.h>
#include<conio.h>

int searchInsert(int* a, int n, int b) {
    int mid,beg=0,end=n-1,flag=0;
    while(beg<=end){
         mid=(beg+end)/2;
        if(a[mid]==b){
            return mid;
        }
        else if(a[mid]>b){
        end=mid-1;
        flag=1;
        }
        else{
        beg=mid+1;
        flag=2;
        }
    }
    if(flag==1)
    return mid;
    else if(flag==2)
    return mid+1;
}

void main(){
    int n1;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n1);

    int* A = (int*)malloc(sizeof(int)*n1);

    printf("Enter the array:\n");
    int i;
    for(i=0;i<n1;i++){
        scanf("%d", &A[i]);
    }

    int number;
    printf("\nEnter number to search/insert :");
    scanf("%d", &number);

    int pos = searchInsert(A, n1, number);

    printf("%d", pos);
}
