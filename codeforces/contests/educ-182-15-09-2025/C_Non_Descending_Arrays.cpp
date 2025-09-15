// Upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

void solve(){
    int n; cin >> n;

    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }   

    vector<ll> b(n+1);
    for (int i = 1; i <= n; i++){
        cin >> b[i];

        if (a[i] > b[i]) swap(a[i], b[i]);
    }

    ll ans = 2;
    for (int i = 2; i <=n; i++){
        if (a[i] >= b[i-1]) ans = ans * 2 % MOD;
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