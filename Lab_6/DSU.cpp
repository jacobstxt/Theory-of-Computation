#include "DSU.h"

DSU::DSU(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int DSU::find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void DSU::unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[a] = b;
}