#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

const int MOD = 998244353;

ll count0 (ll x){
    if (x < 3) return 1;
    return (x - 3)/4 + 2;
}

ll count1(ll x){
    if (x == 0) return 0;
    return (x - 1)/4 + 1;
}

void solve(){
    ll n, m; cin >> n >> m;

    // contar prefix[r] ^ pref[l-1] = 0
    // qtd 0: 4 * n + 3
    // qtd 1: 4 * n + 1

    ll ans = 0;
    ll x0 = count0(m-1);
    ll xn = count0(n) - x0;

    ans = ((xn % MOD) * (x0 % MOD)) % MOD;

    ll x1 = count1(m-1);
    ll xn1 = count1(n) - x1;

    ans = ans + (((xn1 % MOD) * (x1 % MOD)) % MOD);
    ans %= MOD;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}