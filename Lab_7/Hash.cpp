#include "Hash.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>



int hashDivision(int key, int m)
{
    return ((key % m) + m) % m; 
}


int hashMultiplication(int key, int m)
{
    const double A = 0.6180339887;
    double frac = (key * A) - std::floor(key * A);
    return static_cast<int>(std::floor(m * frac)); 
}


HashTable createHashTable(int m)
{
    return HashTable(m);  
}


void ChainedHashInsert(HashTable& table, int key, int (*hashFunc)(int, int))
{
	int m = static_cast<int>(table.size());  // розмір таблиці
	int idx = hashFunc(key, m); // обчислення індексу за допомогою хеш-функції
	auto& chain = table[idx]; // беремо список елементів у цій комірці
    // Якщо ключ вже є — не дублюємо
    if (std::find(chain.begin(), chain.end(), key) != chain.end()) {
        std::cout << "Key " << key << " already exists in the table.\n";
        return;
    }
    chain.push_front(key);   
}


bool ChainedHashSearch(const HashTable& table, int key, int (*hashFunc)(int, int))
{
    int m = static_cast<int>(table.size());
    int idx = hashFunc(key, m);
    const auto& chain = table[idx];

    return std::find(chain.begin(), chain.end(), key) != chain.end();
}



void ChainedHashDelete(HashTable& table, int key, int (*hashFunc)(int, int))
{
    int m = static_cast<int>(table.size());
    int idx = hashFunc(key, m);
    auto& chain = table[idx];

    auto it = std::find(chain.begin(), chain.end(), key);
    if (it != chain.end()) {
        chain.erase(it);
        std::cout << "Key " << key << " deleted.\n";
    }
    else {
        std::cout << "Key " << key << " not found.\n";
    }
}


void ChainedHashShow(const HashTable& table)
{
    int m = static_cast<int>(table.size());
    std::cout << "\n+------------------------------+\n";
    std::cout << "|    Hash table (m=" << std::setw(3) << m << ")       |\n";
    std::cout << "+------------------------------+\n";
    for (int i = 0; i < m; ++i) {
        std::cout << "| [" << std::setw(3) << i << "] -> ";
        const auto& chain = table[i];
        if (chain.empty()) {
            std::cout << "NULL";
        }
        else {
            bool first = true;
            for (int k : chain) {
                if (!first) std::cout << " -> ";
                std::cout << k;
                first = false;
            }
        }
        std::cout << "\n";
    }
    std::cout << "+------------------------------+\n";
}
