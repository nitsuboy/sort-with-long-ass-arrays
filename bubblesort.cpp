#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include "lib.h"
using namespace std;

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
    int e = 6;        //expoente do 10
    int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    //int *A = LAAD(e); //array decrecsente

    auto start = chrono ::steady_clock ::now();

    bubbleSort(A, p(10, e));

    auto end = chrono ::steady_clock ::now();

    auto diff = end - start;

    cout << fixed;
    cout << chrono::duration<long double, milli>(diff).count() << " ms para um array de 10^" << e << "\n";
    cout << chrono::duration<long double>(diff).count() << " s para um array de 10^" << e;

    return 0;
}
