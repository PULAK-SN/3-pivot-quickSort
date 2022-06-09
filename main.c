
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "1PIVOT.h"
#include "3PIVOT.h"

int main()
{
    
    int SIZE = 10000;
    printf("\n--------\t\t---------- SIZE = %d --------\t\t----------\n",SIZE);
    int arr1[SIZE],arr3[SIZE];

    for(int i=0; i<SIZE; ++i)
        arr1[i] = arr3[i] = rand()%(2*SIZE);

    double time_spent = 0.0;
    clock_t begin, end;

 // ------------------------------------------------------------------
    begin = clock();
    onePivotSort(arr1,0,SIZE-1);

    end = clock();

    time_spent = (double)(end - begin) * 1000.0 / (double)CLOCKS_PER_SEC;;
    printf("\nI-Pivot -> The elapsed time is %f ms", time_spent);

// ------------------------------------------------------------------

    begin = clock();

    threePivotSort(arr3,0,SIZE-1);

    end = clock();

    time_spent = (double)(end - begin) * 1000.0 / (double)CLOCKS_PER_SEC;
    printf("\nIII-Pivot -> The elapsed time is %f ms", time_spent);

    // -------------------------------------------------------------
    printf("\n");

    return 0;
}

