#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<int> dist;

void dfs(int u, int p){
    for (auto v : g[u]){
        if (v != p){
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}

void solve(){
    int n, k; cin >> n >> k; 

    vector<int> mark(k);
    for (auto &i : mark) {
        cin >> i;
        i--;
    }

    g.resize(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist.resize(n, -1);

    dist[mark[0]] = 0;
    dfs(mark[0], -1);

    int l = mark[0];
    for (auto x : mark){
        if (dist[x] > dist[l]){
            l = x;
        }
    }

    dist[l] = 0;
    dfs(l, -1);

    int ans = mark[0];
    for (auto x : mark){
        if (dist[x] > dist[ans]){
            ans = x;
        }
    }

    cout << (dist[ans]+1)/2 << "\n";

    dist.clear();
    g.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}