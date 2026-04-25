#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    ll arr[2][n];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    ll dp[2][n];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];

    for (int i = 1; i < n; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1] + arr[0][i]);
        dp[1][i] = max(dp[0][i-1] + arr[1][i], dp[1][i-1]);
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}