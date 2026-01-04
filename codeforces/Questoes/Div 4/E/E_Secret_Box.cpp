#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x, y, z, k; cin >> x >> y >> z >> k;

    ll ans = 0;
    for (ll i = 1; i <= x; i++){
        for (ll j = 1; j <= y; j++){
            if (k % (i * j) != 0) continue;

            ll c = k/(i*j);

            if (c > z) continue;

            ans = max(ans, (x-i+1) * (y-j+1) * (z-c+1));
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