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

int partition_2(int array[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quicksort_2(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition_2(array, low, high);

    // recursive call on the left of pivot
    quicksort_2(array, low, pi - 1);

    // recursive call on the right of pivot
    quicksort_2(array, pi + 1, high);
  }
}

int main()
{
    int e = 4;        //expoente do 10
    //int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    int *A = LAAD(e); //array decrecsente

    auto start = chrono ::steady_clock ::now();

    quicksort_2(A, 0, p(10, e) - 1);

    auto end = chrono ::steady_clock ::now();

    auto diff = end - start;

    cout << fixed;
    cout << "quick sort\n";
    cout << chrono::duration<long double, milli>(diff).count() << " ms para um array de 10^" << e << "\n";
    cout << chrono::duration<long double>(diff).count() << " s para um array de 10^" << e << "\n";

    return 0;
}
