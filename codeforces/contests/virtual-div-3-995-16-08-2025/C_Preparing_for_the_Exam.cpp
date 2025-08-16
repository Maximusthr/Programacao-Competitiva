#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<int> listas(m);
    for (auto &i : listas) cin >> i;
    
    vector<bool> sei(n+1);
    for (int i = 0; i < k; i++){
        int x; cin >> x;
        sei[x] = true;
    }

    if (n-k >= 2) {
        for (int i = 0; i < m; i++){
            cout << 0;
        }
        cout << "\n";
        return;
    }

    if (k == n){
        for (int i = 0; i < m; i++){
            cout << 1;
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < m; i++){
        if (!sei[listas[i]]) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}