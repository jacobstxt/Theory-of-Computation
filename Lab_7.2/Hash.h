#pragma once
#include <iostream>
#include <string>


enum class CellState {
    EMPTY,    
    OCCUPIED, 
    DELETED   
};


struct HashCell {
    int key;
    CellState state;

    HashCell() : key(0), state(CellState::EMPTY) {}
};


enum class ProbeType {
    LINEAR,
    QUADRATIC,
    DOUBLE_HASH
};


struct HashTable {
    HashCell* table;
    int m;         
    int count;     
    ProbeType probe; 
    double c1, c2;   
};


int h1(int k, int m);

int h2(int k, int m);


int hashLinear(int k, int i, int m);

int hashQuadratic(int k, int i, int m, double c1, double c2);

int hashDouble(int k, int i, int m);

HashTable* createHashTable(int m, ProbeType probe, double c1 = 0, double c2 = 0);

void destroyHashTable(HashTable* ht);


int HashInsert(HashTable* ht, int key);


int HashSearch(HashTable* ht, int key);


bool HashDelete(HashTable* ht, int key);


void HashShow(const HashTable* ht);