#include "Heap.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>

int Parent(int i) { return (i - 1) / 2; }
int Left(int i) { return 2 * i + 1; }
int Right(int i) { return 2 * i + 2; }

void MaxHeapify(int* A, int* P, int heapSize, int i) {
    int l = Left(i), r = Right(i), largest = i;

    if (l < heapSize && P[l] > P[largest]) largest = l;
    if (r < heapSize && P[r] > P[largest]) largest = r;

    if (largest != i) {
        std::swap(A[i], A[largest]);
        std::swap(P[i], P[largest]); 
        MaxHeapify(A, P, heapSize, largest);
    }
}

void BuildMaxHeap(int* A, int* P, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        MaxHeapify(A, P, n, i);
}

int HeapExtractMax(int* A, int* P, int& heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга порожня.");
    int maxVal = A[0];
    A[0] = A[heapSize - 1];
    P[0] = P[heapSize - 1]; 
    --heapSize;
    MaxHeapify(A, P, heapSize, 0);
    return maxVal;
}

void HeapIncreaseKey(int* A, int* P, int heapSize, int i, int key) {
    if (i < 0 || i >= heapSize)
        throw std::out_of_range("Помилка: індекс виходить за межі.");
    if (key < P[i])
        throw std::invalid_argument("Помилка: новий ключ менший за поточний.");
    P[i] = key;
    while (i > 0 && P[Parent(i)] < P[i]) {
        std::swap(A[i], A[Parent(i)]);
        std::swap(P[i], P[Parent(i)]);  
        i = Parent(i);
    }
}

void MaxHeapInsert(int* A, int* P, int& heapSize, int val, int key) {
    A[heapSize] = val;
    P[heapSize] = INT_MIN;
    ++heapSize;
    HeapIncreaseKey(A, P, heapSize, heapSize - 1, key);
}


int HeapMax(const int* P, int heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга порожня.");
    return P[0];
}

int HeapMin(const int* P, int heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга порожня.");
    return P[0];
}


void MinHeapify(int* A, int* P, int heapSize, int i) {
    int l = Left(i), r = Right(i), smallest = i;

    if (l < heapSize && P[l] < P[smallest]) smallest = l;
    if (r < heapSize && P[r] < P[smallest]) smallest = r;

    if (smallest != i) {
        std::swap(A[i], A[smallest]);
        std::swap(P[i], P[smallest]);
        MinHeapify(A, P, heapSize, smallest);
    }
}

void BuildMinHeap(int* A, int* P, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        MinHeapify(A, P, n, i);
}

int HeapExtractMin(int* A, int* P, int& heapSize) {
    if (heapSize <= 0)
        throw std::underflow_error("Помилка: черга порожня.");
    int minVal = A[0];
    A[0] = A[heapSize - 1];
    P[0] = P[heapSize - 1];
    --heapSize;
    MinHeapify(A, P, heapSize, 0);
    return minVal;
}

void HeapDecreaseKey(int* A, int* P, int heapSize, int i, int key) {
    if (i < 0 || i >= heapSize)
        throw std::out_of_range("Помилка: індекс виходить за межі.");
    if (key > P[i])
        throw std::invalid_argument("Помилка: новий ключ більший за поточний.");
    P[i] = key;
    while (i > 0 && P[Parent(i)] > P[i]) {
        std::swap(A[i], A[Parent(i)]);
        std::swap(P[i], P[Parent(i)]);
        i = Parent(i);
    }
}

void MinHeapInsert(int* A, int* P, int& heapSize, int val, int key) {
    A[heapSize] = val;
    P[heapSize] = INT_MAX;
    ++heapSize;
    HeapDecreaseKey(A, P, heapSize, heapSize - 1, key);
}


void show(const int* A, const int* P, int n) {
    std::cout << "Значення:  [ ";
    for (int i = 0; i < n; ++i) std::cout << A[i] << " ";
    std::cout << "]\n";
    std::cout << "Пріоритет:   [ ";
    for (int i = 0; i < n; ++i) std::cout << P[i] << " ";
    std::cout << "]\n";
}

void PrintHeapTree(const int* A, const int* P, int heapSize) {
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
            std::cout << "[" << A[idx] << "|p" << P[idx] << "]";
            if (j < count - 1 && idx + 1 < heapSize)
                for (int s = 0; s < spacing * 3; ++s) std::cout << ' ';
        }
        std::cout << '\n';
    }
}