#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m; 
vector<string> g;

void processar(int x, int y){
    int v = x+1;
    while(v < n){
        if (g[v][y] == '.'){
            g[x][y] = '.';
            g[v][y] = '*';
            x = v;
            v++;
        }
        else break;
    }
}

void solve(){
    cin >> n >> m;

    g.resize(n);
    for (auto &i : g) cin >> i;

    for (int i = n-2; i >= 0; i--){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '*') processar(i, j);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << g[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}