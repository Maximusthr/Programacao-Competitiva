#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x, y; cin >> x >> y;

    if (x == y){
        cout << -1 << "\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; i < 62; i++){
        if ((1ll << i) < (max(x, y))) continue;
        else {
            ans = (1ll << i) - max(x, y);
            break;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
