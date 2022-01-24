#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

 void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
  }

int main()
{
    int e = 3;        //expoente do 10
    int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    //int *A = LAAD(e); //array decrecsente

    heapSort(A, p(10, e));

    printf("pronto");

    return 0;
}
