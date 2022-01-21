#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include "lib.h"
using namespace std;

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

// Print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int e = 6;        //expoente do 10
    int *A = LAAA(e); //array aleatorio
    //int *A = LAAC(e); //array crecsente
    //int *A = LAAD(e); //array decrecsente

    auto start = chrono ::steady_clock ::now();

    heapSort(A, p(10, e));

    auto end = chrono ::steady_clock ::now();

    auto diff = end - start;

    cout << fixed;
    cout << chrono::duration<long double, milli>(diff).count() << " ms para um array de 10^" << e << "\n";
    cout << chrono::duration<long double>(diff).count() << " s para um array de 10^" << e;

    return 0;
}
