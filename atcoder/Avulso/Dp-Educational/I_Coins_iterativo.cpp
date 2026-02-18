#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<double> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    double dp[n+1][n+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] += dp[i-1][j] * (1-arr[i]);

            if (j > 0){
                dp[i][j] += dp[i-1][j-1] * arr[i];
            }
        }
    }

    double ans = 0;
    for (int j = n/2 + 1; j <= n; j++){
        ans += dp[n][j];
    }

    cout << fixed << setprecision(10);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}