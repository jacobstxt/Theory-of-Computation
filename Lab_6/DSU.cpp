#include "DSU.h"

DSU::DSU(int n) {
    parent.resize(n);
    rank_.resize(n, 0);
    for (int i = 0; i < n; i++)
        set_make(i);
}

void DSU::set_make(int v) {
    parent[v] = v;
    rank_[v] = 0;
}


int DSU::set_find(int v) {
    if (parent[v] != v)
        parent[v] = set_find(parent[v]); 
    return parent[v];
}


void DSU::set_union(int v1, int v2) {
    int r1 = set_find(v1);
    int r2 = set_find(v2);
    if (r1 == r2) return; 

    if (rank_[r1] < rank_[r2])
        std::swap(r1, r2);

    parent[r2] = r1;
    if (rank_[r1] == rank_[r2])
        rank_[r1]++;
}