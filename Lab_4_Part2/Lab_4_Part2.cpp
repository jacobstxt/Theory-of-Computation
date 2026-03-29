#include <iostream>
#include "Tree.h"
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* root = nullptr;
    int choice;
    datatype val;

    do {
        cout << "\n--- ЧАСТИНА 2: ДЕРЕВО ПОШУКУ (BST) ---" << endl;
        cout << "1. Створити корінь (CreateRootBST)" << endl;
        cout << "2. Додати вузол (InsertNodeBST)" << endl;
        cout << "3. Видалити вузол (DeleteNodeBST)" << endl;
        cout << "4. Пошук вузла (SearchNodeBST)" << endl;
        cout << "5. Наступний/Попередній (Successor/Predecessor)" << endl;
        cout << "6. Відобразити структуру" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть ключ кореня: ";
            cin >> val;
            root = CreateRootBST(val);
            ShowTree(root, 0);
            break;
        case 2:
            cout << "Значення для вставки: ";
            cin >> val;
            InsertNodeBST(root, val);
            ShowTree(root, 0);
            break;
        case 3:
            cout << "Ключ для видалення: ";
            cin >> val;
            {
                Node* target = SearchNodeBST(root, val);
                if (target) {
                    DeleteNodeBST(root, target);
                    cout << "Вузол видалено." << endl;
                }
                else cout << "Не знайдено!" << endl;
            }
            ShowTree(root, 0);
            break;
        case 4:
            cout << "Що шукаємо? ";
            cin >> val;
            if (SearchNodeBST(root, val)) cout << "Знайдено!" << endl;
            else cout << "Відсутній." << endl;
            break;
        case 5:
            cout << "Введіть ключ вузла: ";
            cin >> val;
            {
                Node* target = SearchNodeBST(root, val);
                if (target) {
                    Node* s = SuccessorNodeBST(target);
                    Node* p = PredecessorNodeBST(target);
                    cout << "Попередній: " << (p ? to_string(p->key) : "немає") << endl;
                    cout << "Наступний:  " << (s ? to_string(s->key) : "немає") << endl;
                }
                else cout << "Вузол не знайдено." << endl;
            }
            break;
        case 6:
            if (root) ShowTree(root, 0);
            else cout << "Дерево порожнє." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}