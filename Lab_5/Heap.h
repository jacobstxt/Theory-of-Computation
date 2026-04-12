#pragma once
int Parent(int i);
int Left(int i);
int Right(int i);

void MaxHeapify(int* A, int heapSize, int i);
void BuildMaxHeap(int* A, int n);

void MinHeapify(int* A, int heapSize, int i);
void BuildMinHeap(int* A, int n);

void HeapSort(int* A, int size, bool ascending = true);


void show(int* A, int n);