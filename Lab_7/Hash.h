#pragma once
#include <list>
#include <vector>
#include <string>


int hashDivision(int key, int m);    
int hashMultiplication(int key, int m); 

using HashTable = std::vector<std::list<int>>;

HashTable createHashTable(int m);

void ChainedHashInsert(HashTable& table, int key, int (*hashFunc)(int, int));

bool ChainedHashSearch(const HashTable& table, int key, int (*hashFunc)(int, int));

void ChainedHashDelete(HashTable& table, int key, int (*hashFunc)(int, int));

void ChainedHashShow(const HashTable& table);