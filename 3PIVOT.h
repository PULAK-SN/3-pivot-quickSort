#ifndef _3PIVOT_H_
#define _3PIVOT_H_

#include<stdio.h>

void swap3(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition3(int arr[], int low, int high, int *mp, int *rp)
{
    if(arr[low] > arr[high])
        swap3(&arr[low], &arr[high]);
    if(arr[low+1] < arr[low])
        swap3(&arr[low+1], &arr[low]);
    if(arr[low+1] > arr[high])
        swap3(&arr[high], &arr[low+1]);
    
    int a = low+2;
    int b = low+2;

    int k = b;
    int d = high-1;

    int p = arr[low];
    int q = arr[low+1];
    int r = arr[high];

    while (k <= d)
    {
        if(arr[k] < q)
        {
           if(arr[k] < p)
           {
               // first sub-array
                swap3(&arr[b],&arr[k]);
                swap3(&arr[a],&arr[b]);
                ++a;
                ++b;
           }
           else
           {
                //second sub-array
                swap3(&arr[b], &arr[k]);
                ++b;
           }
        }
        else if(arr[k] > r)
        {
            while(arr[d] > r && k < d)
                --d;

            // fourth sub-array
            swap3(&arr[k],&arr[d]);
            --d;

            if(arr[k] < q)
            {
                if(arr[k] < p)
                {
                    // first sub-array
                        swap3(&arr[b],&arr[k]);
                        swap3(&arr[a],&arr[b]);
                        ++a;
                        ++b;
                }
                else
                {
                        //second sub-array
                        swap3(&arr[b], &arr[k]);
                        ++b;
                }
            }
            
        }
        ++k;
    }

    --a;
    swap3(&arr[a],&arr[low+1]);

    --b;
    swap3(&arr[a], &arr[b]);

    --a;
    swap3(&arr[low], &arr[a]);

    ++d;
    swap3(&arr[d], &arr[high]);
    
    *mp = b;
    *rp = d;
    return a;

}


void threePivotSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int lp,mp, rp;

        lp = partition3(arr,low,high, &mp, &rp);

        threePivotSort(arr,low,lp-1);
        threePivotSort(arr,lp+1,mp-1);
        threePivotSort(arr,mp+1, rp-1);
        threePivotSort(arr,rp+1,high);

    }
}

#endif

