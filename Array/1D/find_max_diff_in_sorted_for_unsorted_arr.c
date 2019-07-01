/**
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5

Return 0 if the array contains less than 2 elements.
**/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>


typedef struct Buckt{
    int Min;
    int Max;
}Buckt;



int MaxGap(int *A, int n1){

    int i,K;

    Buckt *Buckets=(Buckt *)calloc(n1-1, sizeof(Buckt));;

    int Max,Min,prev,mxgap;

    float interval;

    Min= 100000;

    Max= -100000;



    if (n1 < 2)

        return 0;



    for (i = 0; i < n1; i++)

    {

        Min = A[i] < Min ? A[i] : Min;
        Max = A[i] > Max ? A[i] : Max;

        if(i < n1-1)

        Buckets[i].Min = 100000, Buckets[i].Max = -100000;

    }



    if (n1 == 2)

        return Max - Min;



    interval = ((float)(Max - Min) / ((float)n1-1));



    for (i = 0; i < n1; i++)

    {

        if(A[i] == Min || A[i] == Max)

            continue;



        K = ((A[i] - Min) / interval);



        Buckets[K].Max = Buckets[K].Max > A[i] ? Buckets[K].Max : A[i];

        Buckets[K].Min = Buckets[K].Min < A[i] ? Buckets[K].Min : A[i];

    }



    prev = Min;

    mxgap = 0;



    for (i = 0; i < n1-1; i++)

    {

        if(Buckets[i].Min == 100000)

            continue;



        mxgap = mxgap > (Buckets[i].Min - prev) ? mxgap : (Buckets[i].Min - prev);

        prev  = Buckets[i].Max;



    }

    mxgap = mxgap > (Max-prev) ? mxgap : Max - prev;



    free(Buckets);

    return mxgap;

}

void main(){
    int A[] = {6,7,8,3,2};
    int n1 = sizeof(A)/sizeof(int);

    int max = MaxGap(A,n1);

    printf("%d", max);
}
