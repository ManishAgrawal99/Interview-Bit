#include<stdio.h>
#include<conio.h>



void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int arr2[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    int j;
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            swap(&arr2[i], &arr2[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&arr2[i + 1], &arr2[high]);
    return (i + 1);
}

void quickSort(int arr[], int arr2[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, arr2, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, arr2, low, pi - 1);
        quickSort(arr, arr2, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main(){
    int arr1[] = {9, 47, 17, 39, 35, 35, 20, 18, 15, 34, 11, 2, 45, 46, 15, 33, 47, 47, 10, 11, 27};
    int arr2[] = {32, 82, 39, 86, 81, 58, 64, 53, 40, 76, 40, 46, 63, 88, 56, 52, 50, 72, 22, 19, 38};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    quickSort(arr1, arr2, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr1, n);
    printArray(arr2, n);

}
