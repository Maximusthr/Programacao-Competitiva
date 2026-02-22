#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    if (n == 1){
        cout << 0 << "\n";
        return;
    }

    int dp[n+1][3];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0];

        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);

        dp[i][2] = max(dp[i-1][1], dp[i-1][2]);

        if (dp[i][0] < arr[i]) dp[i][0]++;
        else if (dp[i][0] > arr[i]) dp[i][0]--;

        if (dp[i][2] < arr[i]) dp[i][2]++;
        else if (dp[i][2] > arr[i]) dp[i][2]--;
    }

    int ans = max({dp[n][1], dp[n][2]});

    if (ans == n) ans--;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}