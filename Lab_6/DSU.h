#pragma once
#include <vector>

class DSU {
private:
    std::vector<int> parent;
	std::vector<int> rank_; 

public:
    DSU(int n);
    void set_make(int v);
    int  set_find(int v);
    void set_union(int v1, int v2);
};