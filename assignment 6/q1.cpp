#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int main() {
    vector<vector<int>> graph = {
        {0,16,13,0,0,0},
        {0,0,10,12,0,0},
        {0,4,0,0,14,0},
        {0,0,9,0,0,20},
        {0,0,0,7,0,4},
        {0,0,0,0,0,0}
    };

    int s = 0, t = 5;
    int V = graph.size();
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
            pathFlow = min(pathFlow, rGraph[parent[v]][v]);

        for (int v = t; v != s; v = parent[v]) {
            rGraph[parent[v]][v] -= pathFlow;
            rGraph[v][parent[v]] += pathFlow;
        }
        maxFlow += pathFlow;
    }

    cout << maxFlow;
    return 0;
}
