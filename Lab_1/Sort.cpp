#include "Sort.h"
#include <iostream>



void initialize(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
    }
}


void show(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void my_swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int MaxItem(int* A, int first, int last) {
    int max = A[0];
    for (int i = first; i < last; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

int MinItem(int* A, int first, int last) {
    int min = A[0];
    for (int i = first; i < last; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}



void sort_bubble(int* A, int n, int first, int last)
{
    for (int i = first; i < last; i++)
        for (int j = first; j < last - 1 - (i - first); j++)
            if (A[j] > A[j + 1]) {
                my_swap(A[j], A[j + 1]);
                //show(A, n);
            }
}

void sort_inserting(int* A, int n, int first, int last)
{
    int i;
    int j;
    int key;

    for (i = first; i < last; i++)
    {
        key = A[i];
        for (j = i-1; j >= first && A[j] > key; j--)
        {
            A[j + 1] = A[j];
        }
         A[j + 1] = key; 
         //show(A, n);
    }
}


void sort_selection(int* A, int n, int first, int last)
{
    int length = n;
    for (int i = first; i < last; i++) {
        for (int j = i + 1; j < last; j++) {
            if (A[i] > A[j]) {
                my_swap(A[j], A[i]);
                //show(A, n);
            }
        }
    }
}


void Merge(int* A, int first, int mid, int last)
{
    int i = first;
    int j = mid + 1;
    int k = 0;
    int* B = new int[last - first + 1];
    while (i <= mid && j <= last)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= last)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (i = first; i <= last; i++)
    {
        A[i] = B[i - first];
    }
	delete[] B;
}


void MergeSort(int* A, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(A, first, mid);
        MergeSort(A, mid + 1, last);
        Merge(A, first, mid, last);
    }
}

