/**
Given a read only array of n + 1 integers between 1 and n,
find one number that repeats in linear time using less than O(n) space
and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]

Sample Output:

1


**/

#include<stdio.h>
#include<conio.h>

void main(){
    int A[] = {3,4,1,4,1};
    int n1 = 5;

    if(n1 <= 1)
        printf("No Duplicates");

    int slow = A[0];
    int fast = A[A[0]];

    while(slow != fast){
        slow = A[slow];
        fast = A[A[fast]];
    }

    slow = 0;

    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }

    printf("%d", slow);
}
