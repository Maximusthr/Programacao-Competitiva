#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){
    ll x = 1;

    while(b > 0){
        if (b%2) x *= a;
        b >>= 1;
        a *= a;
    }
    return x;
}

void solve(){
    int n; cin >> n;

    ll zero = 0;
    ll um = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 0) zero++;
        if (x == 1) um++;
    }

    ll ans = 0;

    // if (um == 0){
    //     cout << 0 << "\n";
    //     return;
    // }
    // else {
    //     if (zero == 0) ans += um;
    //     else if (zero == 1) ans += um*2;
    //     else if (zero > 1) {
    //         ans += exp(2, zero);
    //         if (um > 1) ans *= um;
    //     }
    // }

    cout << exp(2, zero) * um << "\n";

    // cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}