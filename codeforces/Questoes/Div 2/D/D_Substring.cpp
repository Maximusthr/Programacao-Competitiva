#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    string s; cin >> s;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    vector<vector<int>> dp(n, vector<int> (26));

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        deg[y]++;
    }

    for (int i = 0; i < n; i++){
        dp[i][s[i]-'a']++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (auto v : g[u]){
            deg[v]--;

            for (int i = 0; i < 26; i++){
                dp[v][i] = max(dp[u][i] + (s[v] - 'a' == i ? 1 : 0), dp[v][i]);
            }

            if (deg[v] == 0) q.push(v);
        }
    }
    
    if (topo.size() != n){
        cout << -1 << "\n";
        return;
    }


    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}