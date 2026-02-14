#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (!graph[path[pos - 1]][v]) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

bool hamCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (pos == graph.size())
        return graph[path[pos - 1]][path[0]];

    for (int v = 1; v < graph.size(); v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    vector<int> path(graph.size(), -1);
    path[0] = 0;

    if (hamCycleUtil(graph, path, 1)) {
        for (int v : path) cout << v << " ";
        cout << path[0];
    } else {
        cout << "No Hamiltonian Cycle";
    }
    return 0;
}
