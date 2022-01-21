#include <bits/stdc++.h>
#include <chrono>
#include "lib.h"
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int e = 3;
    int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    //int *A = LAAD(e); //array decrecsente

    auto start = chrono ::steady_clock ::now();

    quickSort(A, 0, p(10, e) - 1);

    auto end = chrono ::steady_clock ::now();

    auto diff = end - start;

    cout << chrono::duration<long double, milli>(diff).count() << " ms para um array de 10^" << e << "\n";
    cout << chrono::duration<long double>(diff).count() << " s para um array de 10^" << e;

    return 0;
}
