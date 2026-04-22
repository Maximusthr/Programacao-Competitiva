#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<ll>> d(n, vector<ll>(n, LINF));
    vector<vector<int>> edges(n, vector<int>(n));
    vector<vector<int>> path(n, vector<int>(n, -1));

    int ans = 0;
    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        d[x][y] = min(d[x][y], w);
        d[y][x] = min(d[y][x], w);
        path[x][y] = y;
        path[y][x] = x;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    for (int i = 0; i < n; i++){
        d[i][i] = 0;
        edges[i][i] = 2;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j || i == k || k == j) continue;

                if (d[i][j] >= d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    // verificar todos os caminhos do grafos e verificar se posso remover uma aresta
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (path[i][j] != -1){
                edges[i][path[i][j]] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (edges[i][j] == 1) ans++;
        }
    }

    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}