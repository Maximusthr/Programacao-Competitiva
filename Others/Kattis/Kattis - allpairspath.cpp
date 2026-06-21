#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, q;
    while(cin >> n >> m >> q && (n || m || q)){
        vector<vector<int>> g(n, vector<int> (n, INF));
        for (int i = 0; i < m; i++){
            int x, y, w; cin >> x >> y >> w;
            g[x][y] = min(g[x][y], w);
        }

        for (int i = 0; i < n; i++){
            g[i][i] = 0;
        }

        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (g[i][k] < INF && g[k][j] < INF){
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int t = 0; t < n; t++){
                    if (g[i][t] < INF && g[t][j] < INF && g[t][t] < 0){
                        g[i][j] = -INF;
                    }    
                }
            }
        }

        while(q--){
            int x, y; cin >> x >> y;

            if (g[x][y] == INF) cout << "Impossible" << "\n";
            else if (g[x][y] == -INF) cout << "-Infinity" << "\n";
            else cout << g[x][y] << "\n";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}