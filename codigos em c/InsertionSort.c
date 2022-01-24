#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main()
{
  int e = 3;        //expoente do 10
  int *A = LAAA(e); //array aleatorio
  //int *A = LAAC(e); //array crecsente
  //int *A = LAAD(e); //array decrecsente

  insertionSort(A, p(10, e));

  printf("pronto");

  return 0;
}
