#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int e = 3;        //expoente do 10
    //int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    int *A = LAAD(e); //array decrecsente

    bubbleSort(A, p(10, e));

    printf("pronto");

    return 0;
}
