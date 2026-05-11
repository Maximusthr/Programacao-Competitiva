#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll h, n; cin >> h >> n;

    vector<ll> d(n), cd(n);
    for (auto &i : d) cin >> i;
    for (auto &i : cd) cin >> i;

    auto ok = [&](ll mid) -> bool {
        ll dam = 0;

        for (int i = 0; i < n; i++){
            ll x = (mid + cd[i] - 1)/cd[i];

            dam += d[i] * x;
            if (dam >= h) return true;
        }
        return (dam >= h);
    };

    ll l = 1, r = 2e12+5;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}