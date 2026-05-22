#include <iostream>
#include <limits>
#include <Windows.h>
#include "Hash.h"

using namespace std;

// ??? Утиліти ?????????????????????????????????????????????????????????????????

void clearInput() {
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}

int readInt(const string& prompt) {
    int v;
    while (true) {
        cout << prompt;
        if (cin >> v) { clearInput(); return v; }
        cout << "  [!] Некоректне введення. Спробуйте ще раз.\n";
        clearInput();
    }
}

double readDouble(const string& prompt) {
    double v;
    while (true) {
        cout << prompt;
        if (cin >> v) { clearInput(); return v; }
        cout << "  [!] Некоректне введення.\n";
        clearInput();
    }
}

// ??? Підменю для однієї хеш-таблиці ?????????????????????????????????????????

void tableMenu(HashTable* ht, const string& title) {
    int choice;
    do {
        cout << "\n  ??? " << title << " ???\n"
            << "  1. Вставити ключ\n"
            << "  2. Пошук ключа\n"
            << "  3. Видалити ключ\n"
            << "  4. Показати таблицю\n"
            << "  0. Назад\n";
        choice = readInt("  Ваш вибір: ");
        switch (choice) {
        case 1: {
            int key = readInt("  Введіть ключ для вставки: ");
            int idx = HashInsert(ht, key);
            if (idx != -1)
                cout << "  [OK] Ключ " << key << " вставлено в комірку " << idx << "\n";
            break;
        }
        case 2: {
            int key = readInt("  Введіть ключ для пошуку: ");
            int idx = HashSearch(ht, key);
            if (idx != -1)
                cout << "  [OK] Ключ " << key << " знайдено в комірці " << idx << "\n";
            else
                cout << "  [--] Ключ " << key << " не знайдено\n";
            break;
        }
        case 3: {
            int key = readInt("  Введіть ключ для видалення: ");
            if (HashDelete(ht, key))
                cout << "  [OK] Ключ " << key << " видалено (позначено DELETED)\n";
            else
                cout << "  [--] Ключ " << key << " не знайдено\n";
            break;
        }
        case 4:
            HashShow(ht);
            break;
        case 0:
            break;
        default:
            cout << "  [!] Невідома команда\n";
        }
    } while (choice != 0);
}

// ??? Головне меню ?????????????????????????????????????????????????????????????

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "????????????????????????????????????????????????\n"
        << "?   Хешування з відкритою адресацією  Lab 7-2 ?\n"
        << "????????????????????????????????????????????????\n\n";

    int m = readInt("  Введіть розмір хеш-таблиці m: ");
    while (m < 2) {
        cout << "  [!] Розмір повинен бути >= 2\n";
        m = readInt("  Введіть розмір хеш-таблиці m: ");
    }

    // Параметри квадратичного зондування
    cout << "\n  Параметри квадратичного зондування:\n";
    double c1 = readDouble("  c1 = ");
    double c2 = readDouble("  c2 = ");

    // Створення трьох таблиць
    HashTable* htLinear = createHashTable(m, ProbeType::LINEAR);
    HashTable* htQuadratic = createHashTable(m, ProbeType::QUADRATIC, c1, c2);
    HashTable* htDouble = createHashTable(m, ProbeType::DOUBLE_HASH);

    cout << "\n  Створено три хеш-таблиці розміром " << m << "\n";
    cout << "  h1(k) = k mod m\n";
    cout << "  h2(k) = 1 + (k mod (m-1))\n";

    int choice;
    do {
        cout << "\n  ?? ГОЛОВНЕ МЕНЮ ??\n"
            << "  1. Лінійне зондування\n"
            << "  2. Квадратичне зондування  (c1=" << c1 << ", c2=" << c2 << ")\n"
            << "  3. Подвійне хешування\n"
            << "  4. Змінити c1, c2 (квадратичне)\n"
            << "  5. Скинути всі таблиці\n"
            << "  0. Вихід\n";
        choice = readInt("  Ваш вибір: ");

        switch (choice) {
        case 1:
            tableMenu(htLinear, "Лінійне зондування");
            break;
        case 2:
            tableMenu(htQuadratic, "Квадратичне зондування");
            break;
        case 3:
            tableMenu(htDouble, "Подвійне хешування");
            break;
        case 4: {
            c1 = readDouble("  Нове c1 = ");
            c2 = readDouble("  Нове c2 = ");
            htQuadratic->c1 = c1;
            htQuadratic->c2 = c2;
            cout << "  [OK] Константи оновлено\n";
            break;
        }
        case 5: {
            destroyHashTable(htLinear);
            destroyHashTable(htQuadratic);
            destroyHashTable(htDouble);
            htLinear = createHashTable(m, ProbeType::LINEAR,0,0);
            htQuadratic = createHashTable(m, ProbeType::QUADRATIC, c1, c2);
            htDouble = createHashTable(m, ProbeType::DOUBLE_HASH,0,0);
            cout << "  [OK] Всі таблиці скинуто\n";
            break;
        }
        case 0:
            break;
        default:
            cout << "  [!] Невідома команда\n";
        }
    } while (choice != 0);

    destroyHashTable(htLinear);
    destroyHashTable(htQuadratic);
    destroyHashTable(htDouble);

    cout << "  До побачення!\n";
    return 0;
}