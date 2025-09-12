#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    int dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] += dp[i][j-1] + (j != k ? dp[i-j][min(j, i-j)] : 0);
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][n] << "\n";
}