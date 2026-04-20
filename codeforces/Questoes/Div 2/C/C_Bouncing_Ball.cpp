#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, p, k; cin >> n >> p >> k;

    string arr; cin >> arr;
    arr = '#' + arr;

    int x, y; cin >> x >> y;

    int dp[n+1][3];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++){
        dp[i][2] = INF;
    }

    // [0] -> y utilizado
    // [1] -> inicio
    // [2] -> 0 e vira 1

    for (int i = 1; i <= n; i++){
        dp[i][0] = y + dp[i-1][0];

        if (i - p >= 0){
            dp[i][1] = dp[i - p][0];
            dp[i][1] = dp[i][1] + (arr[i] == '0' ? x : 0);
        }
        else dp[i][1] = INF;

        if (i - k > 0){
            dp[i][2] = min({dp[i - k][1], dp[i - k][2]});
            if (arr[i] == '0') dp[i][2] += x;
        }
    }

    int ans = INF;
    for (int i = n-k+1; i <= n; i++){
        ans = min({dp[i][1], dp[i][2], ans});
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}