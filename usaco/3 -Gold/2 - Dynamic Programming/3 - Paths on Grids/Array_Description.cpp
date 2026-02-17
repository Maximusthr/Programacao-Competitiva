#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    ll dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));

    
    if (arr[0] != 0) dp[0][arr[0]] = 1;
    else {
        for (int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++){
        if (arr[i] != 0){
            if (abs(arr[i] - arr[i-1]) > 1 && arr[i-1] != 0){
                cout << 0 << "\n";
                return;
            }
            dp[i][arr[i]] += dp[i-1][arr[i]];
            dp[i][arr[i]] %= MOD;
            dp[i][arr[i]] += dp[i-1][arr[i]-1];
            dp[i][arr[i]] %= MOD;
            if (arr[i]+1 <= m) {
                dp[i][arr[i]] += dp[i-1][arr[i]+1];
                dp[i][arr[i]] %= MOD;
            }
        }
        else {
            if (arr[i-1] != 0){
                dp[i][arr[i-1]] = dp[i-1][arr[i-1]] + dp[i-1][arr[i-1]-1] + dp[i-1][arr[i-1]+1];

                if (arr[i-1] > 1) {
                    dp[i][arr[i-1]-1] = dp[i-1][arr[i-1]] + dp[i-1][arr[i-1]-1] + dp[i-1][arr[i-1]-2];
                }

                if (arr[i-1] + 1 <= m) {
                    dp[i][arr[i-1]+1] = dp[i-1][arr[i-1]] + dp[i-1][arr[i-1]+1] + dp[i-1][arr[i-1]+2];
                }
            }
            else {
                for (int j = 1; j <= m; j++){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= MOD;
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= MOD;
                    if (j+1 <= m){
                        dp[i][j] += dp[i-1][j+1];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++){
        ans += dp[n-1][i];
        ans %= MOD;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}