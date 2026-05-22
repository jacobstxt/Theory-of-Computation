#include "Hash.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

using namespace std;

int h1(int k, int m) {
    return ((k % m) + m) % m;
}

int h2(int k, int m) {
    return 1 + (((k % (m - 1)) + (m - 1)) % (m - 1));
}

int hashLinear(int k, int i, int m) {
    return (h1(k, m) + i) % m;
}

int hashQuadratic(int k, int i, int m, double c1, double c2) {
    long long probe = (long long)h1(k, m)
        + (long long)(c1 * i)
        + (long long)(c2 * i * i);
    return (int)(((probe % m) + m) % m);
}

int hashDouble(int k, int i, int m) {
    return (h1(k, m) + (long long)i * h2(k, m)) % m;
}

static int probeIndex(const HashTable* ht, int k, int i) {
    switch (ht->probe) {
    case ProbeType::LINEAR:
        return hashLinear(k, i, ht->m);
    case ProbeType::QUADRATIC:
        return hashQuadratic(k, i, ht->m, ht->c1, ht->c2);
    case ProbeType::DOUBLE_HASH:
        return hashDouble(k, i, ht->m);
    default:
        return 0;
    }
}

HashTable* createHashTable(int m, ProbeType probe, double c1, double c2) {
    if (m < 2) throw invalid_argument("Rozmir tablytsi povynen buty >= 2");
    HashTable* ht = new HashTable();
    ht->table = new HashCell[m];
    ht->m = m;
    ht->count = 0;
    ht->probe = probe;
    ht->c1 = c1;
    ht->c2 = c2;
    return ht;
}

void destroyHashTable(HashTable* ht) {
    if (!ht) return;
    delete[] ht->table;
    delete ht;
}

int HashInsert(HashTable* ht, int key) {
    if (ht->count == ht->m) {
        cout << "  [!] Tablytsia povna!\n";
        return -1;
    }
    int firstDeleted = -1;
    for (int i = 0; i < ht->m; i++) {
        int idx = probeIndex(ht, key, i);
        CellState s = ht->table[idx].state;
        if (s == CellState::OCCUPIED && ht->table[idx].key == key) {
            cout << "  [!] Kliuch " << key << " vzhe isnuie (indeks " << idx << ")\n";
            return -1;
        }
        if (s == CellState::DELETED && firstDeleted == -1) {
            firstDeleted = idx;
        }
        if (s == CellState::EMPTY) {
            int target = (firstDeleted != -1) ? firstDeleted : idx;
            ht->table[target].key = key;
            ht->table[target].state = CellState::OCCUPIED;
            ht->count++;
            return target;
        }
    }
    if (firstDeleted != -1) {
        ht->table[firstDeleted].key = key;
        ht->table[firstDeleted].state = CellState::OCCUPIED;
        ht->count++;
        return firstDeleted;
    }
    cout << "  [!] Ne vdalos vstavyty\n";
    return -1;
}

int HashSearch(HashTable* ht, int key) {
    for (int i = 0; i < ht->m; i++) {
        int idx = probeIndex(ht, key, i);
        CellState s = ht->table[idx].state;
        if (s == CellState::EMPTY) return -1;
        if (s == CellState::OCCUPIED && ht->table[idx].key == key) return idx;
    }
    return -1;
}

bool HashDelete(HashTable* ht, int key) {
    int idx = HashSearch(ht, key);
    if (idx == -1) return false;
    ht->table[idx].state = CellState::DELETED;
    ht->count--;
    return true;
}

void HashShow(const HashTable* ht) {
    cout << "\n  +---------+----------+----------+\n";
    cout << "  |  Index  |   Key    |  State   |\n";
    cout << "  +---------+----------+----------+\n";
    for (int i = 0; i < ht->m; i++) {
        string stateStr, keyStr;
        switch (ht->table[i].state) {
        case CellState::EMPTY:
            stateStr = "EMPTY";
            keyStr = "---";
            break;
        case CellState::DELETED:
            stateStr = "DELETED";
            keyStr = "---";
            break;
        case CellState::OCCUPIED:
            stateStr = "OCCUPIED";
            keyStr = to_string(ht->table[i].key);
            break;
        default:
            stateStr = "?";
            keyStr = "?";
        }
        cout << "  | " << setw(7) << i
            << " | " << setw(8) << keyStr
            << " | " << setw(8) << stateStr << " |\n";
    }
    cout << "  +---------+----------+----------+\n";
    cout << "  Filled: " << ht->count << " / " << ht->m << "\n";
}