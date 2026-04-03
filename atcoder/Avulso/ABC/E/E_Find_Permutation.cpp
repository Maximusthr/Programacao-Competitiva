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
        swap(x, y);

        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> topo;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0) topo.push(i);
    }

    vector<int> ans;

    while(!topo.empty()){
        if (topo.size() > 1){
            cout << "No" << "\n";
            return;
        }

        int u = topo.front();
        topo.pop();
        ans.push_back(u);
        for (auto v : g[u]){
            deg[v]--;
            if (deg[v] == 0){
                topo.push(v);
            }
        }
    }

    vector<int> id(n+1);
    for (int i = 0; i < n; i++){
        id[ans[i]+1] = n-i;
    }

    cout << "Yes" << "\n";
    for (int i = 1; i <= n; i++){
        cout << id[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}