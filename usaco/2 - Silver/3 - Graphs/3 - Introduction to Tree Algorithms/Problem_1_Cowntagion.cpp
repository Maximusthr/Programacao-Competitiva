#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

int days = 0;

void dfs(int u, int pai){
    if (!vis[u]) vis[u] = true;

    int cows = g[u].size() + (pai == -1 ? 1 : 0);

    int c = 1;
    while (c < cows){
        c *= 2;
        days++;
    }

    for (auto v : g[u]){
        if (!vis[v]){
            days++;
            dfs(v, u);
        }
    }
}

void solve(){
    int n; cin >> n;

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;

        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    cout << days << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    solve();
}