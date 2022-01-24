#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int i, int j)
{
    int v0 = a[i], v1 = a[(i+j+1)/2], v2 = a[j];

    int v = v0 < v1 ? v1 < v2 ? v1 : v0 < v2 ? v2 : v0 : v0 < v2 ? v0 : v1 < v2 ? v2 : v1;
    while (i < j) {
        while (a[i] < v && ++i < j)
            ;
        while (v < a[j] && i < --j)
            ;
        int t = a[j]; a[j] = a[i]; a[i]= t;
    }

    a[i] = v;
    return j;
}

void quicksort(int a[], int lo, int hi) //quicksort padrão
{
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

int partition_2(int *a, int low, int high) 
{
    
  int pivot = a[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (a[j] <= pivot) {
        
      i++;
      
      swap(&a[i], &a[j]);
    }
  }
  
  swap(&a[i + 1], &a[high]);
  
  return (i + 1);
}

void quicksort_2(int *a, int low, int high) // quicksort padrão
{
  if (low < high) {
      
    int pi = partition_2(a, low, high);

    quicksort_2(a, low, pi - 1);

    quicksort_2(a, pi + 1, high);
  }
}

int main()
{
    int e = 3;        //expoente do 10
    //int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    int *A = LAAD(e); //array decrecsente

    quicksort_2(A, 0, p(10, e) - 1);

    printf("pronto");

    return 0;
}
