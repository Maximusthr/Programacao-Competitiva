#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] = arr[i-1] + prefix[i-1];
    }

    ll ans = 0;
    for (int i = 0; i <= k; i++){
        ans = max({ans, prefix[n - (k - i)] - prefix[2*i]});
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