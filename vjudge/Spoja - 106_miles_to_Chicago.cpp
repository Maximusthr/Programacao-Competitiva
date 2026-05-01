#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n;
    while(cin >> n){
        if (n == 0) return;
        int m; cin >> m;
    
        vector<vector<double>> g(n, vector<double>(n));
        for (int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            x--, y--;
            double p; cin >> p;
            g[x][y] = p/100.00;
            g[y][x] = p/100.00;
        }
    
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    g[i][j] = max(g[i][k] * g[k][j], g[i][j]);
                }
            }
        }
    
        cout << fixed << setprecision(6);
        cout << 100 * g[0][n-1] << " percent\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}