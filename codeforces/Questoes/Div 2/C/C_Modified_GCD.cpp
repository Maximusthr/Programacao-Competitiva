#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;
    
    ll v = __gcd(x, y);

    set<int, greater<int>> fatores;

    for (int i = 1; i * i <= v; i++){
        if (v % i == 0){
            fatores.insert(i);
            fatores.insert(v/i);
        }
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        if (l > v){
            cout << -1 << "\n";
            continue;
        }

        bool ok = false;

        for (auto it : fatores){
            if (it <= min(1ll * r, v) && it >= l){
                cout << it << "\n";
                ok = true;
                break;
            }
        }

        if (!ok) cout << -1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}