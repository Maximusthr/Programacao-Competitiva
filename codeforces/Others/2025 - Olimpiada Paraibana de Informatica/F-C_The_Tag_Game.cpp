#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

vector<vector<int>> g(MAX);

vector<int> dist_a;
vector<int> dist_b;

void bfs_a(int u){
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for (auto w : g[v]){
            if (dist_a[w] == -1){
                dist_a[w] = dist_a[v] + 1;
                q.push(w);
            }
        }
    }
}

void bfs_b(int u){
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for (auto w : g[v]){
            if (dist_b[v] + 1 >= dist_a[w]) continue;

            if (dist_b[w] == -1){
                dist_b[w] = dist_b[v] + 1;
                q.push(w);
            }
        }
    }
}

void solve(){
    
    int n, m; cin >> n >> m;
   
    dist_a.assign(n, -1);
    dist_b.assign(n, -1);
    
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dist_a[0] = 0;
    bfs_a(0);
    
    m--; 

    dist_b[m] = 0;
    bfs_b(m);
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (dist_a[i] > dist_b[i] && dist_b[i] != -1) ans = max(ans, dist_a[i] * 2);
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}