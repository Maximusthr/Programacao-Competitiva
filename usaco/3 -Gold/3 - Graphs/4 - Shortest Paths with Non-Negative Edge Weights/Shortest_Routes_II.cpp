#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, q; cin >> n >> m >> q;

    ll dist[n+5][n+5];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i][j] = LINF;
        }
    }

    for (int i = 0; i < m; i++){
        ll x, y, c; cin >> x >> y >> c;
        x--, y--;
        dist[x][y] = min(dist[x][y], c);
        dist[y][x] = min(dist[y][x], c);
    }

    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                if (dist[i][k] < LINF && dist[k][j] < LINF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while(q--){
        int x, y; cin >> x >> y;
        x--, y--;

        if (dist[x][y] == LINF) cout << -1 << "\n";
        else cout << dist[x][y] << "\n";
    }
}