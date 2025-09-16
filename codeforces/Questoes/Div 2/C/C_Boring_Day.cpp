#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, l, r; cin >> n >> l >> r;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    int lll = 0, rr = 0;
    ll sum = 0;

    int ans = 0;
    while (lll < n){
        while (rr < n && sum < l){
            sum += arr[rr++];
        }
        if (sum >= l && sum <= r){
            lll = rr;
            ans++;
            sum = 0;
        }
        else {
            sum -= arr[lll++];
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