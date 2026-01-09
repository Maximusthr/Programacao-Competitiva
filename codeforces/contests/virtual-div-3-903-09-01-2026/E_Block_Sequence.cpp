#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    auto pode = [&](int pos) -> int {
        if (pos > n) return n + 1;
        if (pos == n) return 0;
        return dp[pos];
    };

    for (int i = n-1; i >= 0; i--){
        dp[i] = min(dp[i+1] + 1, pode(i + arr[i] + 1));
    }

    cout << dp[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}