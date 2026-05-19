#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

const int INF = 1e9; 

struct Edge {
    int u, v, weight;
};


vector<Edge> prim(int n, int start, vector<vector<pair<int, int>>>& adj) {
	vector<int>  min_e(n, INF); // яка мінімальна вага ребра для кожної вершини
	vector<int>  sel_e(n, -1); // через яку вершину каркасу іде це найдешевше ребро
	vector<bool> visited(n, false); // чи вершина вже включена в каркас

	min_e[start] = 0; // початок з вершини start
    vector<Edge> mst;

    for (int iter = 0; iter < n; iter++) {
        // знаходимо невідвідану вершину з мінімальною вагою
        int v = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (v == -1 || min_e[i] < min_e[v]))
                v = i;
        }

        visited[v] = true;

        // додаємо ребро до каркасу (крім стартової вершини)
        if (sel_e[v] != -1) {
            mst.push_back({ sel_e[v], v, min_e[v] });
        }

        // оновлюємо min_e для сусідів вершини v
        for (auto [to, w] : adj[v]) {
            if (!visited[to] && w < min_e[to]) {
                min_e[to] = w;
                sel_e[to] = v;
            }
        }
    }

    return mst;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 9; 
    int start = 0; 

    vector<Edge> edges = {

        {0, 1,  4}, {0, 7,  8},
        {1, 2,  8}, {1, 7, 11},
        {2, 3,  7}, {2, 8,  2}, 
        {2, 5,  4}, {3, 4,  9}, 
        {3, 5, 14}, {4, 5, 10},
        {5, 6,  2}, {6, 7,  1}, 
        {6, 8,  6}, {7, 8,  7}
    };


    vector<vector<pair<int, int>>> adj(n);
    for (auto& e : edges) {
        adj[e.u].push_back({ e.v, e.weight });
        adj[e.v].push_back({ e.u, e.weight });
    }

    vector<Edge> mst = prim(n, start, adj);

    cout << "Мiнiмальний каркас (алгоритм Прiма, початок з вершини " << start << "):\n";
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