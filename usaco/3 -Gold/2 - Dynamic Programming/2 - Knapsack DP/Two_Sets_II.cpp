#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int sum = n * (n + 1)/2;

    if (sum % 2) {
        cout << 0 << "\n";
        return 0;
    }

    sum /= 2;

    vector<vector<int>> dp(n, vector<int> (sum + 1));

    dp[0][0] = 1;

    for (int i = 1; i < n; i++){
        for (int j = 0; j <= sum; j++){
            dp[i][j] = dp[i-1][j];

            if (j - i >= 0) dp[i][j] += dp[i-1][j-i];

            dp[i][j] %= MOD;
        }
    }

    cout << dp[n-1][sum] << "\n";
}