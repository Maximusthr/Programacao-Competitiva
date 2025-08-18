#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

vector<vector<int>> g(MAX);
vector<int> dist(MAX, -1);

void dfs(int u){
    for (auto v : g[u]){
        if (dist[v] == -1){
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

void solve(){
    int n; cin >> n;

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;

        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist[0] = 0;
    dfs(0);
    
    int maior = 0;
    int pos = -1;
    for (int i = 0; i < n; i++){
        maior = max(maior, dist[i]);
        if (maior == dist[i]){
            pos = i;
        }
    }

    dist.assign(MAX, -1);
    dist[pos] = 0;
    dfs(pos);

    maior = 0;
    for (int i = 0; i < n; i++){
        maior = max(maior, dist[i]);
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}