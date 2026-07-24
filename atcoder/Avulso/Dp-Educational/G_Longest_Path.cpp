#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> q;
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        if (deg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (auto v : g[u]){
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
                dp[v] = max(dp[v], dp[u] + 1);
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(dp[i], maxi);
    }
    cout << maxi << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}