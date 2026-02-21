#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<bool> suco(m+1);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int y; cin >> y;
            g[i].push_back(y);
        }
    }

    for (int i = 0; i < n; i++){
        bool ok = false;
        for (auto j : g[i]){
            if (!suco[j]){
                ok = true;
                suco[j] = true;
                cout << j << "\n";
                break;
            }
        }
        if (!ok){
            cout << 0 << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}