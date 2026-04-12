#include "Heap.h"
#include <iostream>
#include <algorithm>



int Parent(int i) { return (i - 1) / 2; }
int Left(int i) { return 2 * i + 1; }
int Right(int i) { return 2 * i + 2; }



void MaxHeapify(int* A, int heapSize, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;

    if (l < heapSize && A[l] > A[largest])
        largest = l;
    if (r < heapSize && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        std::swap(A[i], A[largest]);
        MaxHeapify(A, heapSize, largest);
    }
}

void BuildMaxHeap(int* A, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        MaxHeapify(A, n, i);
}



void MinHeapify(int* A, int heapSize, int i) {
    int l = Left(i);
    int r = Right(i);
    int smallest = i;

    if (l < heapSize && A[l] < A[smallest])
        smallest = l;
    if (r < heapSize && A[r] < A[smallest])
        smallest = r;

    if (smallest != i) {
        std::swap(A[i], A[smallest]);
        MinHeapify(A, heapSize, smallest);
    }
}

void BuildMinHeap(int* A, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        MinHeapify(A, n, i);
}



void HeapSort(int* A, int size, bool ascending) {
    if (ascending) {
        BuildMaxHeap(A, size);
        for (int i = size - 1; i >= 1; --i) {
            std::swap(A[0], A[i]);
            MaxHeapify(A, i, 0);
        }
    }
    else {
        BuildMinHeap(A, size);
        for (int i = size - 1; i >= 1; --i) {
            std::swap(A[0], A[i]);
            MinHeapify(A, i, 0);
        }
    }
}


void show(int* A, int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; ++i)
        std::cout << A[i] << " ";
    std::cout << "]\n";
}