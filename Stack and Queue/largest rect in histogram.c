/**


Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

**/

#include<stdio.h>
#include<conio.h>

int largestRectangleArea(int *A, int n1) {
    int *stack;
    int top = -1, ans = 0, area = 0, i;
    stack = (int *)malloc((n1+1)*sizeof(int));
    stack[++top] = -1;


    for (i = 0; i < n1;) {
        if (top == 0 || A[i] >= A[stack[top]]) {
            stack[++top] = i;
            i += 1;
        } else {
            area = A[stack[top--]] * (i-stack[top]-1);
            ans = (area > ans) ? area : ans;
        }
    }

    while(top != 0) {
        area = A[stack[top--]] * (n1-stack[top]-1);
        ans = (area > ans) ? area : ans;
    }
    free(stack);
    return(ans);
}

void main(){
    int A[] = {2,1,5,6,2,3};
    int n = sizeof(A)/sizeof(A[0]);

    int ans = largestRectangleArea(&A, n);

    printf("%d ", ans);

}
