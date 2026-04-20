#include "Heap.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>

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

int HeapMax(const int* A, int heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга з пріоритетами порожня.");
    return A[0];
}

int HeapExtractMax(int* A, int& heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга з пріоритетами порожня.");

    int maxVal = A[0];
    A[0] = A[heapSize - 1];
    --heapSize;
    MaxHeapify(A, heapSize, 0);
    return maxVal;
}

void HeapIncreaseKey(int* A, int heapSize, int i, int key) {
    if (i < 0 || i >= heapSize)
        throw std::out_of_range("Помилка: індекс виходить за межі купи.");
    if (key < A[i])
        throw std::invalid_argument(
            "Помилка: новий ключ менший за поточний (зменшення ключа не допускається).");

    A[i] = key;
    while (i > 0 && A[Parent(i)] < A[i]) {
        std::swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}

void MaxHeapInsert(int* A, int& heapSize, int key) {
    A[heapSize] = INT_MIN; 
    ++heapSize;
    HeapIncreaseKey(A, heapSize, heapSize - 1, key);
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

int HeapMin(const int* A, int heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга з пріоритетами порожня.");
    return A[0];
}

int HeapExtractMin(int* A, int& heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга з пріоритетами порожня.");

    int minVal = A[0];
    A[0] = A[heapSize - 1];
    --heapSize;
    MinHeapify(A, heapSize, 0);
    return minVal;
}

void HeapDecreaseKey(int* A, int heapSize, int i, int key) {
    if (i < 0 || i >= heapSize)
        throw std::out_of_range("Помилка: індекс виходить за межі купи.");
    if (key > A[i])
        throw std::invalid_argument(
            "Помилка: новий ключ більший за поточний (збільшення ключа не допускається).");

    A[i] = key;
    while (i > 0 && A[Parent(i)] > A[i]) {
        std::swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}

void MinHeapInsert(int* A, int& heapSize, int key) {
    A[heapSize] = INT_MAX;  
    ++heapSize;
    HeapDecreaseKey(A, heapSize, heapSize - 1, key);
}


void show(int* A, int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; ++i)
        std::cout << A[i] << " ";
    std::cout << "]\n";
}

void PrintHeapTree(const int* A, int heapSize) {
    if (heapSize == 0) {
        std::cout << "(порожня)\n";
        return;
    }

    int levels = static_cast<int>(std::floor(std::log2(heapSize))) + 1;
    int idx = 0;

    for (int lvl = 0; lvl < levels && idx < heapSize; ++lvl) {
        int count = 1 << lvl;
        int spacing = (1 << (levels - lvl)) - 1;
        int indent = (1 << (levels - lvl - 1)) - 1;

        for (int s = 0; s < indent * 3; ++s) std::cout << ' ';

        for (int j = 0; j < count && idx < heapSize; ++j, ++idx) {
            std::cout << std::setw(3) << A[idx];
            if (j < count - 1 && idx + 1 < heapSize)
                for (int s = 0; s < spacing * 3; ++s) std::cout << ' ';
        }
        std::cout << '\n';
    }
}