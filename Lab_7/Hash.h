#pragma once
#include <list>
#include <vector>
#include <string>

// ─── Хеш-функції ────────────────────────────────────────────────
int hashDivision(int key, int m);       // метод ділення
int hashMultiplication(int key, int m); // метод множення

// ─── Хешування методом ланцюгів ─────────────────────────────────
// Тип хеш-таблиці: вектор двозв'язних списків цілих чисел
using HashTable = std::vector<std::list<int>>;

HashTable createHashTable(int m);

void ChainedHashInsert(HashTable& table, int key,
    int (*hashFunc)(int, int));

bool ChainedHashSearch(const HashTable& table, int key,
    int (*hashFunc)(int, int));

void ChainedHashDelete(HashTable& table, int key,
    int (*hashFunc)(int, int));

void ChainedHashShow(const HashTable& table);