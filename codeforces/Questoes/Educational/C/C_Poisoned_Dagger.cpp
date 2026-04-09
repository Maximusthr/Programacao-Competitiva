#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    ll k; cin >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](ll mid) -> bool {
        ll foi = 0;
        for (int i = 0; i < n; i++){
            if (i + 1 < n){
                foi += min(arr[i+1] - arr[i], mid);
            }
            if (i + 1 == n){
                foi += mid;
            }
        }
        return foi >= k;
    };

    ll l = 0, r = 1e18+5;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)) r = mid;
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