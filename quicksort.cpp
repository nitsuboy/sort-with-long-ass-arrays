#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include "lib.h"
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int i, int j) {
    int v0 = a[i], v1 = a[(i+j+1)/2], v2 = a[j];
    /* pivot: median of v0,v1,v2 */
    int v = v0 < v1 ? v1 < v2 ? v1 : v0 < v2 ? v2 : v0 : v0 < v2 ? v0 : v1 < v2 ? v2 : v1;
    while (i < j) {
        while (a[i] < v && ++i < j)
            ;
        while (v < a[j] && i < --j)
            ;
        int t = a[j]; a[j] = a[i]; a[i]= t; //swap
    }
    /* i == j; that's where the pivot belongs */
    a[i] = v;
    return j;
}

void quicksort(int a[], int lo, int hi) {
    while (lo < hi) {
        int j = partition(a, lo, hi);
        if (j - lo < hi -j) {
            quicksort(a, lo, j-1);
            lo = j+1;
        } else {
            quicksort(a, j+1, hi);
            hi = j-1;
        }
    }
}

int main()
{
    int e = 3;        //expoente do 10
    //int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    int *A = LAAD(e); //array decrecsente

    //printArray(A,p(10, e));

    auto start = chrono ::steady_clock ::now();

    quicksort(A, 0, p(10, e) - 1);

    auto end = chrono ::steady_clock ::now();

    auto diff = end - start;

    

    cout << fixed;
    cout << "quick sort\n";
    cout << chrono::duration<long double, milli>(diff).count() << " ms para um array de 10^" << e << "\n";
    cout << chrono::duration<long double>(diff).count() << " s para um array de 10^" << e << "\n";

    //printArray(A,p(10, e));

    return 0;
}
