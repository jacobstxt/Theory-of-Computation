#pragma once
int Parent(int i);
int Left(int i);
int Right(int i);


void MaxHeapify(int* A, int heapSize, int i);
void BuildMaxHeap(int* A, int n);
int HeapMax(const int* A, int heapSize);
int HeapExtractMax(int* A, int& heapSize);
void HeapIncreaseKey(int* A, int heapSize, int i, int key);
void MaxHeapInsert(int* A, int& heapSize, int key);


void MinHeapify(int* A, int heapSize, int i);
void BuildMinHeap(int* A, int n);
int HeapMin(const int* A, int heapSize);
int HeapExtractMin(int* A, int& heapSize);
void HeapDecreaseKey(int* A, int heapSize, int i, int key);
void MinHeapInsert(int* A, int& heapSize, int key);


void show(int* A, int n);
void PrintHeapTree(const int* A, int heapSize);