#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+1;

vector<bool> vis(MAX);

void bfs(int n, int m){
    queue<pair<int, int>> fila;
    fila.push({n, 0});
    
    while (!fila.empty()){
        int u = fila.front().first;
        int aux = fila.front().second;
        vis[u] = true;
        fila.pop();
        
        if (u == m) {
            cout << aux << "\n";
            return;
        }
        
        if (u-1 >= 0 && !vis[u-1]){
            fila.push({u-1, aux+1});
            vis[u-1] = true;
        }
        if (u*2 <= MAX-1 && !vis[u*2]){
            fila.push({u*2, aux+1});
            vis[u*2] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    if (n >= m) cout << n-m << "\n";
    else {
        bfs(n, m);
    }
}
