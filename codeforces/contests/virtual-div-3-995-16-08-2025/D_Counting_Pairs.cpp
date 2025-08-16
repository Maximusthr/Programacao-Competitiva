#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; ll x, y;
    cin >> n >> x >> y;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);
    ll ans = 0;

    for (int i = 0; i < n; i++){
        ll vx = sum - arr[i] - x;
        ll vy = sum - arr[i] - y;

        int idx_x = upper_bound(arr.begin(), arr.end(), vx) - arr.begin();
        int idx_y = lower_bound(arr.begin(), arr.end(), vy) - arr.begin();

        if (idx_x > i && idx_y <= i) ans--;

        ans += idx_x - idx_y;
    }

    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}