#include<stdio.h>

#include "3PIVOT.h"

int main()
{
    int arr[] = {20, 10, 30, 70, 50, 19, 23, 5, 8, 29, 11, 100};

    // 10, 20, 30, 5, 8, 11, 19, 23, 29, 50, 70, 100
    // l   m   r      a       b       c

    int n = sizeof(arr) / sizeof(int);

    threePivotSort(arr, 0, n-1);

    printf("\n\n [ ");
    for(int i=0; i<n; ++i)
        printf("%d, ",arr[i]);
    printf("]\n\n");

    return 0;
}
