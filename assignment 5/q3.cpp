#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int v, vector<vector<int>>& g, vector<bool>& vis, stack<int>& st) {
    vis[v] = true;
    for (int u : g[v])
        if (!vis[u]) dfs1(u, g, vis, st);
    st.push(v);
}

void dfs2(int v, vector<vector<int>>& gr, vector<bool>& vis) {
    vis[v] = true;
    for (int u : gr[v])
        if (!vis[u]) dfs2(u, gr, vis);
}

int main() {
    int V = 5;
    vector<vector<int>> g(V), gr(V);

    g[0]={2}; g[2]={1}; g[1]={0}; g[0].push_back(3); g[3]={4};
    for (int i = 0; i < V; i++)
        for (int j : g[i])
            gr[j].push_back(i);

    stack<int> st;
    vector<bool> vis(V,false);

    for (int i = 0; i < V; i++)
        if (!vis[i]) dfs1(i, g, vis, st);

    fill(vis.begin(), vis.end(), false);
    int scc = 0;

    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (!vis[v]) {
            dfs2(v, gr, vis);
            scc++;
        }
    }

    cout << scc;
    return 0;
}
