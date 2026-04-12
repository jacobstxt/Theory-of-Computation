#include <windows.h>
#include <iostream>
#include "Heap.h"

using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int n = 0;

void inputArray() {
    cout << "Введiть кiлькiсть елементiв: ";
    cin >> n;
    cout << "Введiть елементи:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  A[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "Масив введено: ";
    show(arr, n);
}

void showMenu() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║          HEAP OPERATIONS             ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ 1. Ввести масив                      ║\n";
    cout << "║ 2. Побудувати Max-Heap (незростаюча) ║\n";
    cout << "║ 3. Побудувати Min-Heap (неспадна)    ║\n";
    cout << "║ 4. Сортування за зростанням          ║\n";
    cout << "║ 5. Сортування за спаданням           ║\n";
    cout << "║ 6. Вивести поточний масив            ║\n";
    cout << "║ 0. Вихiд                             ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << "Ваш вибiр: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            inputArray();
            break;

        case 2:
            if (n == 0) { cout << "Спочатку введiть масив!\n"; break; }
            BuildMaxHeap(arr, n);
            cout << "Max-Heap: ";
            show(arr, n);
            break;

        case 3:
            if (n == 0) { cout << "Спочатку введiть масив!\n"; break; }
            BuildMinHeap(arr, n);
            cout << "Min-Heap: ";
            show(arr, n);
            break;

        case 4:
            if (n == 0) { cout << "Спочатку введiть масив!\n"; break; }
            HeapSort(arr, n, true);
            cout << "Вiдсортовано за зростанням: ";
            show(arr, n);
            break;

        case 5:
            if (n == 0) { cout << "Спочатку введiть масив!\n"; break; }
            HeapSort(arr, n, false);
            cout << "Вiдсортовано за спаданням: ";
            show(arr, n);
            break;

        case 6:
            if (n == 0) { cout << "Масив порожнiй!\n"; break; }
            cout << "Поточний масив: ";
            show(arr, n);
            break;

        case 0:
            cout << "До побачення!\n";
            break;

        default:
            cout << "Невiрний вибiр!\n";
        }
    } while (choice != 0);

    return 0;
}