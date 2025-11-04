#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<vector<char>> arr(n+1, vector<char> (n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int> (n+1));

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (arr[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][n] << "\n";
}