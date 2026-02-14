#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoring(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoring(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int m = 3;
    vector<int> color(4, 0);

    if (graphColoring(graph, m, color, 0)) {
        for (int c : color)
            cout << c << " ";
    } else {
        cout << "Solution does not exist";
    }
    return 0;
}
