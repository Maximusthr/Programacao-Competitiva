#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, r, c; cin >> n >> m >> r >> c;

    r--;
    c--;

    vector<string> s(n);
    for (auto &i : s) cin >> i;

    if (s[r][c] == 'B'){
        cout << 0 << "\n";
        return;
    }

    bool ok = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == 'B') {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    if (!ok) {
        cout << -1 << "\n";
        return;
    }

    bool linha = false;
    bool coluna = false;
    for (int i = 0; i < m; i++){
        if (s[r][i] == 'B'){
            linha = true;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        if (s[i][c] == 'B'){
            coluna = true;
            break;
        }
    }

    if (coluna || linha) {
        cout << 1 << "\n";
    }
    else cout << 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}