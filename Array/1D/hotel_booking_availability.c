#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int int_cmp(const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}

void main(){
    int n;
    int i = 0;
    int j = 0;
    int K;

    printf("Enter the number of rooms:\n");
    scanf("%d", &K);

    printf("Enter the number of entries: ");
    scanf("%d", &n);

    int n1=n;
    int n2=n;

    int arrive[n];
    int depart[n];

    printf("Enter the arrival dates:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arrive[i]);
    }

    printf("\nEnter the departure dates:\n");
    for(i=0;i<n;i++){
        scanf("%d", &depart[i]);
    }

    qsort(arrive, n1, sizeof(int), int_cmp);
    qsort(depart, n2, sizeof(int), int_cmp);

    int current = arrive[0];


    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(depart[j]<=arrive[i]){
            K++;
            j++;
        }
        else{
            K--;
            i++;
            if(K<0){
                printf("\nBooking not possible\n");
                return;
            }
        }
    }
    printf("\nBooking possible\n");

}
