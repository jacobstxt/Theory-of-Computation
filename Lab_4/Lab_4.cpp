#include <iostream>
#include "Tree.h"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* root = nullptr;
    int choice;

    do {
        cout << "\n--- ЧАСТИНА 1: ЗБАЛАНСОВАНЕ ДЕРЕВО ---" << endl;
        cout << "1. Створити збалансоване дерево" << endl;
        cout << "2. Відобразити структуру" << endl;
        cout << "3. Обходи (PreOrder, InOrder, PostOrder)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            cout << "Введіть кількість вузлів: ";
            cin >> n;
            root = CreateTree(n, nullptr);
            ShowTree(root, 0);
            break;
        }
        case 2:
            if (root) ShowTree(root, 0);
            else cout << "Дерево порожнє." << endl;
            break;
        case 3:
            if (root) {
                cout << "\nPreOrder:  "; PreOrder(root);
                cout << "\nInOrder:   "; InOrder(root);
                cout << "\nPostOrder: "; PostOrder(root);
                cout << endl;
            }
            else cout << "Дерево порожнє." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}