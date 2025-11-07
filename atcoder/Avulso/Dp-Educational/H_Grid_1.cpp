#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<string> s(n);
    for (auto &i : s) cin >> i;

    vector<vector<int>> dp(n, vector<int> (m));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }

            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];

            dp[i][j] %= MOD;
        }
    }

    cout << dp[n-1][m-1] << "\n";
}