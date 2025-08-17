#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    
    ll n, m; cin >> n >> m;

    vector<ll> b(n);
    for (auto &i : b) cin >> i;

    vector<ll> g(m);
    for (auto &i : g) cin >> i;

    sort(b.begin(), b.end(), greater<ll> ());
    sort(g.begin(), g.end());

    if (b[0] > g[0]){
        cout << -1 << "\n";
        return;
    }

    ll sum = accumulate(g.begin(), g.end(), 0ll);

    if (n == 1){
        if (b[0] != g[0]){
            cout << -1 << "\n";
        }
        else cout << sum << "\n";

        return;
    }

    ll ans = 0;
    
    bool ok = false;
    if (b[0] == g[0]) ok = true;

    ans += (ok ? 0 : b[0]);
    ans -= (ok ? 0 : b[1]);
    ans += sum;

    for (int i = 1; i < n; i++){
        ans += b[i] * m;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}