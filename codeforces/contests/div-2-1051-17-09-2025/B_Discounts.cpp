#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> disc(k);
    for (auto &i : disc) cin >> i;

    sort(arr.begin(), arr.end(), greater<ll> ());
    sort(disc.begin(), disc.end());

    ll ans = 0;

    ll total = accumulate(arr.begin(), arr.end(), 0ll);

    for (int i = 0, l = 0; l < n && i < k; i++){
        ll last = 0, v = 0;
        for (int j = 0; l < n && j < disc[i]; j++){
            last += arr[l];
            total -= arr[l];
            l++;
            v++;
        }
        if (v < disc[i]) {
            ans += last;
            continue;
        }
        last -= arr[l-1];
        ans += last;
    }
    ans += total;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}