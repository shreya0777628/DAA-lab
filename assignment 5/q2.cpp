#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    vector<pair<int,int>> edges = {{2,3},{3,1},{4,0},{4,1},{5,0},{5,2}};

    vector<int> indeg(V,0);
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        indeg[e.second]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u])
            if (--indeg[v] == 0) q.push(v);
    }
    return 0;
}
