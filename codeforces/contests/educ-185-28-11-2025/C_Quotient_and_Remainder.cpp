#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    ll n, k; cin >> n >> k;

    vector<ll> q(n), r(n);
    for (auto &i : q) cin >> i;
    for (auto &i : r) cin >> i;

    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end());

    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < n){
        ll v = r[j] + 1;
        ll x = q[i] * v + r[j];

        if (x <= k){
            ans++;
            i++, j++;
        }
        else i++;
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