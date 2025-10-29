// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<ll> dp(n+1);
    for (int i = 0; i < n; i++){
        dp[i] = b[i];
        for (int j = 0; j < i; j++){
            if (a[j] <= a[i]){
                dp[i] = max(dp[i], dp[j] + b[i]);
            }
        }
    }

    ll total = accumulate(b.begin(), b.end(), 0ll);

    cout << total - *max_element(dp.begin(), dp.end()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}