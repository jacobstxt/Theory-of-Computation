#pragma once
#include <vector>

class DSU {
private:
    std::vector<int> parent;

public:
    DSU(int n);
    int find(int v);
    void unite(int a, int b);
};