#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> mat(m, vector<int> (n));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            mat[i][j]--;
        }
    }

    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++){
        for (int j = 1; j < n-1; j++){
            g[mat[i][j]].push_back(mat[i][j+1]);
            deg[mat[i][j+1]]++;
        }
    }

    queue<int> topo;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0) topo.push(i);
    }

    vector<int> ans;
    while(!topo.empty()){
        int u = topo.front();
        topo.pop();

        ans.push_back(u);

        for (auto v : g[u]){
            deg[v]--;
            if (deg[v] == 0) topo.push(v);
        }
    }

    if (ans.size() != n) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}