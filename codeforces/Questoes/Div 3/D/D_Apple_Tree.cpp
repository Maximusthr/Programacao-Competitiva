#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<ll> sum;

void dfs(int u, int e){
    if (g[u].size() == 1 && g[u][0] == e){
        sum[u] = 1;
    }
    else {
        for (auto v : g[u]){
            if (v == e) continue;
            dfs(v, u);
            sum[u] += sum[v];
        }
    }
}

void solve(){
    int n; cin >> n;
    
    g.assign(n, vector<int> ());
    sum.assign(n, 0);

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;    
        x--, y--;

        cout << (sum[x] * sum[y]) << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}