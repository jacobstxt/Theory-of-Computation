#include <iostream>
#include <windows.h>   
#include "Hash.h"



static int (*currentHash)(int, int) = hashDivision;


void printHashMenu()
{
    std::cout << "\n--- Хеш-функція ---\n"
        << "1. Метод ділення  (h = k mod m)\n"
        << "2. Метод множення (h = floor(m*(k*A mod 1)))\n"
        << "Поточна: "
        << (currentHash == hashDivision ? "ділення" : "множення")
        << "\nВибір: ";
}


void printMenu()
{
    std::cout << "\n╔══════════════════════════╗\n"
        << "║     Lab_07_01  Меню      ║\n"
        << "╠══════════════════════════╣\n"
        << "║ 1. Вставити ключ         ║\n"
        << "║ 2. Знайти ключ           ║\n"
        << "║ 3. Видалити ключ         ║\n"
        << "║ 4. Показати таблицю      ║\n"
        << "║ 5. Змінити хеш-функцію   ║\n"
        << "║ 0. Вихід                 ║\n"
        << "╚══════════════════════════╝\n"
        << "Вибір: ";
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    int m = 0;
    std::cout << "Введіть розмір хеш-таблиці (m): ";
    while (!(std::cin >> m) || m <= 0) {
        std::cout << "Некоректне значення. Введіть натуральне число: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    HashTable table = createHashTable(m);
    std::cout << "Хеш-таблицю розміром " << m << " створено.\n";

    int choice = -1;
    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0) {
            std::cout << "До побачення!\n";
            break;
        }

        switch (choice) {

            // ── Вставка ─────────────────────────────────────────────
        case 1: {
            int key;
            std::cout << "Введіть ключ: ";
            std::cin >> key;
            ChainedHashInsert(table, key, currentHash);
            std::cout << "Ключ " << key
                << " -> слот " << currentHash(key, m) << "\n";
            break;
        }

              // ── Пошук ───────────────────────────────────────────────
        case 2: {
            int key;
            std::cout << "Введіть ключ для пошуку: ";
            std::cin >> key;
            bool found = ChainedHashSearch(table, key, currentHash);
            std::cout << "Ключ " << key
                << (found ? " ЗНАЙДЕНО" : " НЕ ЗНАЙДЕНО")
                << " (слот " << currentHash(key, m) << ")\n";
            break;
        }

              // ── Видалення ───────────────────────────────────────────
        case 3: {
            int key;
            std::cout << "Введіть ключ для видалення: ";
            std::cin >> key;
            ChainedHashDelete(table, key, currentHash);
            break;
        }

              // ── Відображення ────────────────────────────────────────
        case 4:
            ChainedHashShow(table);
            break;

            // ── Вибір хеш-функції ────────────────────────────────────
        case 5: {
            int hChoice;
            printHashMenu();
            std::cin >> hChoice;
            if (hChoice == 1) {
                currentHash = hashDivision;
                std::cout << "Обрано: метод ділення.\n";
            }
            else if (hChoice == 2) {
                currentHash = hashMultiplication;
                std::cout << "Обрано: метод множення.\n";
            }
            else {
                std::cout << "Невідомий вибір.\n";
            }
            break;
        }

        default:
            std::cout << "Невідома команда.\n";
        }
    }

    return 0;
}