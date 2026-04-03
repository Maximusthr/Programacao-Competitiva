#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m;

    while(cin >> n >> m && (n || m)){
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            deg[y]++;
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
                if (deg[v] == 0) q.push(v);
            }
        }

        for (int i = 0; i < n; i++){
            cout << topo[i] + 1 << " \n"[i == n-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}