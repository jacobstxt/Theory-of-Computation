#pragma once
int Parent(int i);
int Left(int i);
int Right(int i);

void MaxHeapify(int* A, int* P, int heapSize, int i);
void BuildMaxHeap(int* A, int* P, int n);
int HeapMax(const int* A, int heapSize);
int HeapExtractMax(int* A, int* P, int& heapSize);
void HeapIncreaseKey(int* A, int* P, int heapSize, int i, int key);
void MaxHeapInsert(int* A, int* P, int& heapSize, int val, int key);

void MinHeapify(int* A, int* P, int heapSize, int i);
void BuildMinHeap(int* A, int* P, int n);
int HeapMin(const int* A, int heapSize);
int HeapExtractMin(int* A, int* P, int& heapSize);
void HeapDecreaseKey(int* A, int* P, int heapSize, int i, int key);
void MinHeapInsert(int* A, int* P, int& heapSize, int val, int key);

void show(const int* A, const int* P, int n);
void PrintHeapTree(const int* A, const int* P, int heapSize);