#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include "lib.h"
using namespace std;

void insertionSort(int array[], int size)
{
  for (int step = 1; step < size; step++)
  {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main()
{
  int e = 6;        //expoente do 10
  int *A = LAAA(e); //array aleatorio
  //int *A = LAAC(e); //array crecsente
  //int *A = LAAD(e); //array decrecsente

  auto start = chrono ::steady_clock ::now();

  insertionSort(A, p(10, e));

  auto end = chrono ::steady_clock ::now();

  auto diff = end - start;

  cout << fixed;
  cout << chrono::duration<long double, milli>(diff).count() << " ms para um array de 10^" << e << "\n";
  cout << chrono::duration<long double>(diff).count() << " s para um array de 10^" << e;

  return 0;
}
