#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    map<ll, int> freq;
    ll sum = 0;

    freq[0] = 0;
    for (int i = 1; i <= n; i++){
        int a; cin >> a;
        sum += a;
        dp[i] = dp[i-1];
        if (freq.find(sum) != freq.end()){
            dp[i] = max(dp[i], 1 + dp[freq[sum]]);
        }
        freq[sum] = i;
    }

    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}