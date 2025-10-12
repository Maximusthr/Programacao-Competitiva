#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e5 + 5;

vector<vector<int>> g;
vector<bool> vis;
vector<int> sz;
vector<bool> vis2;

int maior = 0;

void dfs(int u){
    if (!vis[u]) vis[u] = true;

    sz[u] = 1;

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v);
            sz[u] += sz[v];
            maior = max(maior, sz[u]);
        }
    }
}

void update(int u, int maior){
    if (!vis2[u]) vis2[u] = true;

    sz[u] = max(maior, sz[u]);

    for (auto v : g[u]){
        if (!vis2[v]){
            update(v, maior);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    g.resize(MAX);
    vis.resize(MAX);
    sz.resize(MAX);
    vis2.resize(MAX);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a; cin >> a;
        vector<int> v(a);
        for (int j = 0; j < a; j++){
            cin >> v[j];
            v[j]--;
        }

        for (int j = 1; j < a; j++){
            g[v[j]].push_back(v[j-1]);
            g[v[j-1]].push_back(v[j]);
        }
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            update(i, maior);
            maior = 0;
        }
    }

    for (int i = 0; i < n; i++){
        cout << sz[i] << " \n"[i==n-1];
    }
}   
