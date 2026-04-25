#include <windows.h>
#include <iostream>
#include <climits>
#include "Heap.h"

using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int prior[MAX_SIZE];
int heapSize = 0;
bool heapBuilt = false;
bool isMaxHeap = false;

void inputArray() {
    int n;
    cout << "Введiть кiлькiсть елементiв: ";
    cin >> n;
    if (n <= 0 || n > MAX_SIZE) { cout << "Невiрна кiлькiсть!\n"; return; }
    heapSize = n;
    heapBuilt = false;
    cout << "Введiть елементи (значення i пріоритет):\n";
    for (int i = 0; i < heapSize; ++i) {
        cout << "  [" << i << "] значення   = "; cin >> arr[i];
        cout << "  [" << i << "] пріоритет  = "; cin >> prior[i];
    }
    cout << "Масив введено:\n";
    show(arr, prior, heapSize);
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
            BuildMaxHeap(arr, prior, heapSize);
            isMaxHeap = true;
            heapBuilt = true;
            cout << "Max-Heap побудовано:\n";
            show(arr, prior, heapSize);
            break;

        case 3:
            if (heapSize == 0) { cout << "Спочатку введiть масив!\n"; break; }
            BuildMinHeap(arr, prior, heapSize);
            isMaxHeap = false;
            heapBuilt = true;
            cout << "Min-Heap побудовано:\n";
            show(arr, prior, heapSize);
            break;

        case 4:
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            try {
                if (isMaxHeap)
                    cout << "Максимальний пріоритет: " << HeapMax(prior, heapSize)
                    << ", значення: " << arr[0] << "\n";
                else
                    cout << "Мiнiмальний пріоритет: " << HeapMin(prior, heapSize)
                    << ", значення: " << arr[0] << "\n";
            }
            catch (const exception& e) { cout << e.what() << "\n"; }
            break;

        case 5:
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            try {
                if (isMaxHeap) {
                    int val = HeapExtractMax(arr, prior, heapSize);
                    cout << "Витягнуто елемент зі значенням: " << val << "\n";
                }
                else {
                    int val = HeapExtractMin(arr, prior, heapSize);
                    cout << "Витягнуто елемент зi значенням: " << val << "\n";
                }
                cout << "Купа пiсля витягнення:\n";
                show(arr, prior, heapSize);
            }
            catch (const exception& e) { cout << e.what() << "\n"; }
            break;

        case 6: {
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            int idx, key;
            cout << "Введiть iндекс (0.." << heapSize - 1 << "): "; cin >> idx;
            cout << "Введiть новий пріоритет: "; cin >> key;
            try {
                if (isMaxHeap)
                    HeapIncreaseKey(arr, prior, heapSize, idx, key);
                else
                    HeapDecreaseKey(arr, prior, heapSize, idx, key);
                cout << "Купа пiсля змiни пріоритету:\n";
                show(arr, prior, heapSize);
            }
            catch (const exception& e) { cout << e.what() << "\n"; }
            break;
        }

        case 7: {
            if (!heapBuilt) { cout << "Спочатку побудуйте купу!\n"; break; }
            if (heapSize >= MAX_SIZE) { cout << "Купа заповнена!\n"; break; }
            int val, key;
            cout << "Введiть значення: ";  cin >> val;
            cout << "Введiть пріоритет: "; cin >> key;
            try {
                if (isMaxHeap)
                    MaxHeapInsert(arr, prior, heapSize, val, key);
                else
                    MinHeapInsert(arr, prior, heapSize, val, key);
                cout << "Купа пiсля вставки:\n";
                show(arr, prior, heapSize);
            }
            catch (const exception& e) { cout << e.what() << "\n"; }
            break;
        }

        case 8:
            if (heapSize == 0) { cout << "Масив порожнiй!\n"; break; }
            cout << "Поточний масив:\n";
            show(arr, prior, heapSize);
            break;

        case 9:
            if (heapSize == 0) { cout << "Купа порожня!\n"; break; }
            cout << "Дерево купи:\n";
            PrintHeapTree(arr, prior, heapSize);
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