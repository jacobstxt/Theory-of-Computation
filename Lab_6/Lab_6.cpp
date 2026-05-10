#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "DSU.h"

using namespace std;

struct Edge {
    int u, v, weight;
};

void sort(vector<Edge>& edges) { // сортування ребер за вагою
    int n = (int)edges.size();
    for (int i = 1; i < n; i++) {
        Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = key;
    }
}

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    sort(edges); // сортує ребра за вагою

	DSU dsu(n); // створюємо DSU для n вершин
	vector<Edge> mst; // вектор для зберігання ребер мінімального каркаса

	for (Edge& e : edges) { // проходимо по відсортованих ребрах

        // якщо кінці ребра в різних компонентах — додаємо до каркасу
        if (dsu.set_find(e.u) != dsu.set_find(e.v)) {
			mst.push_back(e); // додаємо ребро до мінімального каркаса
			dsu.set_union(e.u, e.v); // об'єднуємо компоненти, до яких належать кінці ребра
			if ((int)mst.size() == n - 1) // якщо в каркасі вже n-1 ребер, то він готовий
                break; 

        }
    }
    return mst; 
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 9; 

    vector<Edge> edges = {
     {0, 1,  4}, {0, 7,  8},
     {1, 2,  8}, {1, 7, 11},
     {2, 3,  7}, {2, 8,  2},
     {2, 5,  4}, {3, 4,  9},
     {3, 5, 14}, {4, 5, 10},
     {5, 6,  2}, {6, 7,  1}, 
     {6, 8,  6}, {7, 8,  7}
    };

    vector<Edge> mst = kruskal(n, edges);


    cout << "Мiнiмальний каркас (алгоритм Краскала):\n";
    cout << "-------------------------------------------\n";
    int totalWeight = 0;
    for (auto& e : mst) {
        cout << "  " << e.u << " -- " << e.v
            << "   вага: " << e.weight << "\n";
        totalWeight += e.weight;
    }
    cout << "-------------------------------------------\n";
    cout << "Загальна вага: " << totalWeight << "\n";
   

    return 0;
}