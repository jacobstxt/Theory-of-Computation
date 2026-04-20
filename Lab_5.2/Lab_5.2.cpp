#include <windows.h>
#include <iostream>
#include <climits>
#include "Heap.h"

using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int heapSize = 0;
bool heapBuilt = false;
bool isMaxHeap = false;


void inputArray() {
    int n;
    cout << "Введiть кiлькiсть елементiв: ";
    cin >> n;
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Невiрна кiлькiсть елементiв!\n";
        return;
    }
    heapSize = n;
    heapBuilt = false;
    cout << "Введiть елементи:\n";
    for (int i = 0; i < heapSize; ++i) {
        cout << "  A[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "Масив введено: ";
    show(arr, heapSize);
}

void showMenu() {
    cout << "\n╔══════════════════════════════════════════╗\n";
    cout << "║           HEAP OPERATIONS                ║\n";
    cout << "╠══════════════════════════════════════════╣\n";
    cout << "║  1. Ввести масив                         ║\n";
    cout << "║  2. Побудувати Max-Heap                  ║\n";
    cout << "║  3. Побудувати Min-Heap                  ║\n";
    cout << "║  4. Отримати максимум / мiнiмум          ║\n";
    cout << "║  5. Витягти максимум / мiнiмум           ║\n";
    cout << "║  6. Збiльшити / зменшити ключ за iндексом║\n";
    cout << "║  7. Вставити елемент                     ║\n";
    cout << "║  8. Вивести масив                        ║\n";
    cout << "║  9. Вивести дерево купи                  ║\n";
    cout << "║  0. Вихiд                                ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
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
            if (heapSize == 0) { cout << "Спочатку введiть масив!\n"; break; }
            BuildMaxHeap(arr, heapSize);
            isMaxHeap = true;
            heapBuilt = true;
            cout << "Max-Heap побудовано: ";
            show(arr, heapSize);
            break;

        case 3:
            if (heapSize == 0) { cout << "Спочатку введiть масив!\n"; break; }
            BuildMinHeap(arr, heapSize);
            isMaxHeap = false;
            heapBuilt = true;
            cout << "Min-Heap побудовано: ";
            show(arr, heapSize);
            break;

        case 4:
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            try {
                if (isMaxHeap)
                    cout << "Максимум: " << HeapMax(arr, heapSize) << "\n";
                else
                    cout << "Мiнiмум: " << HeapMin(arr, heapSize) << "\n";
            }
            catch (const exception& e) {
                cout << e.what() << "\n";
            }
            break;

        case 5:
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            try {
                if (isMaxHeap) {
                    int val = HeapExtractMax(arr, heapSize);
                    cout << "Витягнуто максимум: " << val << "\n";
                }
                else {
                    int val = HeapExtractMin(arr, heapSize);
                    cout << "Витягнуто мiнiмум: " << val << "\n";
                }
                cout << "Купа пiсля витягнення: ";
                show(arr, heapSize);
            }
            catch (const exception& e) {
                cout << e.what() << "\n";
            }
            break;

        case 6: {
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            int idx, key;
            cout << "Введiть iндекс (0.." << heapSize - 1 << "): ";
            cin >> idx;
            cout << "Введiть новий ключ: ";
            cin >> key;
            try {
                if (isMaxHeap)
                    HeapIncreaseKey(arr, heapSize, idx, key);
                else
                    HeapDecreaseKey(arr, heapSize, idx, key);
                cout << "Купа пiсля змiни ключа: ";
                show(arr, heapSize);
            }
            catch (const exception& e) {
                cout << e.what() << "\n";
            }
            break;
        }

        case 7: {
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            if (heapSize >= MAX_SIZE) { cout << "Купа заповнена!\n"; break; }
            int key;
            cout << "Введiть значення для вставки: ";
            cin >> key;
            try {
                if (isMaxHeap)
                    MaxHeapInsert(arr, heapSize, key);
                else
                    MinHeapInsert(arr, heapSize, key);
                cout << "Купа пiсля вставки: ";
                show(arr, heapSize);
            }
            catch (const exception& e) {
                cout << e.what() << "\n";
            }
            break;
        }

        case 8:
            if (heapSize == 0) { cout << "Масив порожнiй!\n"; break; }
            cout << "Поточний масив: ";
            show(arr, heapSize);
            break;

        case 9:
            if (heapSize == 0) { cout << "Купа порожня!\n"; break; }
            cout << "Дерево купи:\n";
            PrintHeapTree(arr, heapSize);
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