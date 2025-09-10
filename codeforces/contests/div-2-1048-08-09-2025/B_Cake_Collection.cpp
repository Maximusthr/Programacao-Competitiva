#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m; cin >> n >> m;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    
    sort(arr.begin(), arr.end(), greater<ll>());
    
    ll ans = 0;
    for (int i = 0; i < n && i < m; i++){
        ans += arr[i] * (m-i);
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