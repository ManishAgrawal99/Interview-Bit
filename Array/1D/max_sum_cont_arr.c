#include<stdio.h>
#include<conio.h>

void main(){
    int n,i;

    printf("Enter the number of elements in the array; ");
    scanf("%d",&n);
    int A[n];

    printf("Enter the elements in the array");
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    int max = -5000;
    int temp = 0;

    for(i=0;i<n;i++){
        temp += A[i];
        if(temp>max){
            max = temp;
        }
        if(temp<0){
            temp=0;
        }
    }
    printf("contiguous subarray within an array (containing at least one number) which has the largest sum is :%d", max);
}
