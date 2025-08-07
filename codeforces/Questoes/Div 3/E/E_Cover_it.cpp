#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;



void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> dist(n, -1);
    
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto w : g[v]){
            if (dist[w] == -1){
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }
    }
   
    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < n; i++){
        if (dist[i] % 2) odd.push_back(i);
        else even.push_back(i);
    }

    if (odd.size() <= even.size()){
        cout << odd.size() << "\n";
        for (auto &i : odd) cout << ++i << " ";
    }
    else {
        cout << even.size() << "\n";
        for (auto &i : even) cout << ++i << " ";
    }

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}