#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include "DSU.h"

using namespace std;

struct Edge {
    int u, v, weight;
};

// сортування
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int n = 9; // кількість вершин

    vector<Edge> edges = {
        {0,1,4}, {0,7,8}, {1,2,8}, {1,7,11},
        {2,3,7}, {2,8,2}, {2,5,4}, {3,4,9},
        {3,5,14}, {4,5,10}, {5,6,2}, {6,7,1},
        {6,8,6}, {7,8,7}
    };

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);

    vector<Edge> mst; // мінімальний каркас
    int totalWeight = 0;

    for (Edge e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            dsu.unite(e.u, e.v);
        }
    }

    cout << "Мiнiмальний каркас:\n";
    for (auto e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    cout << "Сума ваг = " << totalWeight << endl;

    return 0;
}