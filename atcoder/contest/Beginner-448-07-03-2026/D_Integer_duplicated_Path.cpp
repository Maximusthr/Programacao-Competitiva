#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> vis;
vector<int> arr;
vector<bool> pode;
map<int, int> mapa;

vector<bool> ans;

void dfs(int u, int pai){
    if (!vis[u]){
        vis[u] = true;
        if (mapa[arr[u]] > 0) {
            pode[u] = 1;
            mapa[arr[u]]++;
        }
        else {
            mapa[arr[u]]++;
        }

        if (pai != -1){
            if (pode[pai]) pode[u] = 1;
        }

        if (pode[u]) ans[u] = 1;
    }

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v, u);
        }
    }

    mapa[arr[u]]--;
    if (mapa[arr[u]] <= 1) pode[u] = 0;
    if (pai != -1){
        if (pode[pai]) pode[u] = 0;
    }
}

void solve(){
    int n; cin >> n;
    g.resize(n);
    vis.resize(n);
    pode.resize(n);
    arr.resize(n);
    ans.resize(n);
            
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++){
        if (ans[i]) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}