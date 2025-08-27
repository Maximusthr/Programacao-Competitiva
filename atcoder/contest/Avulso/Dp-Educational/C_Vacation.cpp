#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<array<ll, 3>> p(n);

    for (int i = 0; i < n; i++){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    
    ll dp[3][100005];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = p[0][0];
    dp[1][0] = p[0][1];
    dp[2][0] = p[0][2];

    for (int i = 1; i < n; i++){
        for (int j = 0; j < 3; j++){
            if (j == 0){
                dp[j][i] = max(dp[1][i-1], dp[2][i-1]) + p[i][j];
            }
            else if (j == 1){
                dp[j][i] = max(dp[0][i-1], dp[2][i-1]) + p[i][j];
            }
            else {
                dp[j][i] = max(dp[0][i-1], dp[1][i-1]) + p[i][j];
            }
        }
    }

    cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}