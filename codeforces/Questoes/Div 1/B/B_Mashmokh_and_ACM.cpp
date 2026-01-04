#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;

    ll dp[k+5][n+5];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++){
        dp[1][i] = 1;
    }

    for (int i = 2; i <= k; i++){
        for (int j = 1; j <= n; j++){
            for (int mult = j; mult <= n; mult += j){
                dp[i][j] = (dp[i][j] + dp[i-1][mult]) % MOD;
            }
        }
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans = (ans + dp[k][i]) % MOD;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}