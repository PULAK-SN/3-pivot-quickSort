#ifndef _1PIVOT_H_
#define _1PIVOT_H_

#include<stdio.h>

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition1(int arr[], int low, int high)
{
    int x = arr[high];

    int i = low - 1;

    for(int j=low; j<high; ++j)
    {
        if(arr[j] <= x)
        {
            ++i;
            swap1(&arr[i], &arr[j]);
        }
    }
    swap1(&arr[i+1], &arr[high]);
    return (i+1);
}


int onePivotSort(int arr[], int low, int high)
{
    if(low<high){
        int q = partition1(arr, low, high);
        onePivotSort(arr, low, q-1);
        onePivotSort(arr,q+1, high);
    }
}

#endif