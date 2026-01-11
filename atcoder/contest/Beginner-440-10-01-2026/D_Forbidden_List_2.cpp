#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    while(q--){
        ll x, y; cin >> x >> y;

        ll behind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        ll l = x, r = 1e12;
        while(l < r){
            ll mid = l + (r-l)/2;

            ll pos = mid-x+1;
            ll xx = lower_bound(arr.begin(), arr.end(), mid+1) - arr.begin();
            pos -= xx;
            pos += behind;

            if (pos >= y) r = mid;
            else l = mid + 1;
        }

        cout << l << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}