#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 501;
vector<int> graph[N], revgraph[N];
vector<bool> vis(N), vis2(N);
vector<int> path;

vector<bool> comp(N);

void dfs(int u){
    vis[u] = true;

    for (int v : graph[u]){
        if (!vis[v]) dfs(v);
    }

    path.push_back(u);
}

void dfs2(int u, vector<int> &comp_nodes){
    vis2[u] = true;

    for (int i : revgraph[u]){
        if (!vis2[i]) dfs2(i, comp_nodes);
    }

    comp[u] = true;
    comp_nodes.push_back(u);
}

void solve(){
    int n; cin >> n;

    for (int i = 1; i <= n; i++){
        graph[i].resize(n);
        for (int j = 0; j < n; j++) cin >> graph[i][j];

        // logica da preferencia dos presentes
        while(graph[i].back() != i) graph[i].pop_back();

        // coloco no grafo dos presentes
        for (int j : graph[i]) revgraph[j].push_back(i);
    }

    // Kosaraju
    for (int i = 1; i <= n; i++){
        if (!vis[i]) dfs(i);
    }

    reverse(path.begin(), path.end());

    vector<int> ans(n+1);
    for (int i : path){
        if (!vis2[i]){
            vector<int> comp_nodes;
            dfs2(i, comp_nodes);

            // loop sobre as vacas procurando o presente

            for (int j : comp_nodes){
                for (int k : graph[j]){
                    if (comp[k]){
                        ans[j] = k;
                        break;
                    }
                }
            }
            for (int j : comp_nodes) comp[j] = false;
        }
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    solve();
}