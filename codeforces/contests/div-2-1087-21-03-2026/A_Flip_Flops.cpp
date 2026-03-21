#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, c, k; cin >> n >> c >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++){
        if (c >= arr[i]){
            ll aux = c - arr[i];
            arr[i] += min(k, aux);
            k -= min(k, aux);
            c += arr[i];
        }
    }

    cout << c << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}