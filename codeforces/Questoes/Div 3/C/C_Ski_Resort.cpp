#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, q; cin >> n >> k >> q;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans = 0;
    int c = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] <= q){
            c++;
        }
        if (arr[i] > q){
            if (c >= k){
                ll x = c - k + 1;
                ans += x * (c+1) - x * (c + k)/2;
            }
           
            c = 0;
        }
    }
    if (c > 0){
        if (c >= k){
            ll x = c - k + 1;
            ans += x * (c+1) - x * (c + k)/2;
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