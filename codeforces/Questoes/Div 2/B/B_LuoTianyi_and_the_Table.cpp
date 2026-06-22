#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> arr(n * m);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    
    if (n > m) swap(n, m);

    ll ans = 0;
    ans = arr.back() * (n * m - 1) - ((n * m - n) * arr[0]) - (n-1) * arr[1];
    ans = max(ans, arr.back() * (n * m - n) - ((n * m - 1) * arr[0]) + (n-1) * arr[n*m-2]);

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}