// to do later

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    // n²
    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + arr[i-1];
    }

    ll ans = accumulate(arr.begin(), arr.end(), 0ll);
    ll original = ans;

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            ll v = (j + i + 2) * (j - i + 1);

            ll pre = prefix[j+1] - prefix[i];

            ans = max(v + original - pre, ans);
        }
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