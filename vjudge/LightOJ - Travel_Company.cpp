#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int c = 1;
const double eps = 1e-9;

void solve(){
    int n, r, p; cin >> n >> r >> p;

    vector<vector<int>> g(n, vector<int> (n, INF));
    for (int i = 0; i < r; i++){
        int x, y; cin >> x >> y;
        int a, b; cin >> a >> b;
        
        g[x][y] = min(g[x][y], p*b - a);
    }

    for (int i = 0; i < n; i++){
        g[i][i] = 0;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    bool flag = false;
    for (int i = 0; i < n; i++){
        if (g[i][i] < 0){
            flag = true;
        }
    }

    cout << "Case " << c++ << ": ";
    if (flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}