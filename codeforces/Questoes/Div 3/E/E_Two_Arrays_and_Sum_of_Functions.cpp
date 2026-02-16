#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

void solve(){
    int n; cin >> n;

    vector<ll> a(n);
    for (auto &i : a) cin >> i;

    vector<ll> b(n);
    for (auto &i : b) cin >> i;

    for (int i = 0; i < n; i++){
        a[i] = a[i] * (i+1) * (n-i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans = (ans + ((a[i] % MOD * b[i] % MOD) % MOD) % MOD);
    }

    cout << ans % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}