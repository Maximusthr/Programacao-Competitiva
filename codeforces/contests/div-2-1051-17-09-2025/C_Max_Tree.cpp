#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n-1; i++){
        int x, y, w1, w2; cin >> x >> y >> w1 >> w2;
        x--, y--;
        if (w1 > w2){
            g[x].push_back(y);
            deg[y]++;
        }
        else {
            g[y].push_back(x);
            deg[x]++;
        }
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

    vector<int> id(n+1);
    for (int i = 0; i < topo.size(); i++){
        id[topo[i]+1] = n-i;
    }

    for (int i = 1; i <= n; i++){
        cout << id[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}