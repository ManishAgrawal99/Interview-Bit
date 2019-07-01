#include<stdio.h>
#include<conio.h>
#include<math.h>

/*
You are in an infinite 2D grid where you can move in any of the 8 directions :
(x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)

    You are given a sequence of points and the order in which you need to cover the points.
    Give the minimum number of steps in which you can achieve it. You start from the first point.
*/

void main(){
    int i, j, n, max, temp;
    printf("Enter the number of points to access: ");
    scanf("%d", &n);

    int X[n];
    int Y[n];

    printf("Enter the X coordinates of the points");
    for(i=0;i<n;i++){
        scanf("%d", &X[i]);
    }

    printf("Enter the Y coordinates of the points");
    for(i=0;i<n;i++){
        scanf("%d", &Y[i]);
    }

    int steps = 0;
    for(i=0;i<n-1;i++){
        max = abs(X[i+1] - X[i]);
        temp = abs(Y[i+1]-Y[i]);
        if(max<temp){
            max = temp;
        }
        steps+=max;
    }

    printf("The number of steps required is %d",steps);
}
