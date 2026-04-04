#pragma once

void initialize(int* A, int n);
void show(int* A, int n);
void my_swap(int& a, int& b);
int MaxItem(int* A, int first, int last);
int MinItem(int* A, int first, int last);


void sort_bubble(int* A, int n, int first, int last);
void sort_inserting(int* A, int n, int first, int last);
void sort_selection(int* A, int n, int first, int last);



//Methods Lab_1
void Merge(int* A, int first, int mid, int last);
void MergeSort(int* A, int first, int last);


//Methods Lab_2
void QuickSort(int* A, int first, int last);
void Partition(int* A, int first, int last, int& pivot);
void RandomizedPartition(int* A, int first, int last, int& pivot);
int RandomizedSelect(int A[], int p, int r, int i);


//Methods Lab_3
void CountingSort(int* A, int n, int first, int last);
void CountingSortByDigit(int arr[], int n, int digitPlace, bool lastLoopAsc = true);
void RadixSort(int arr[], int n, bool digitsAsc = true, bool lastLoopAsc = true);