#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;
const int MAX = 1e5+5;

ll dp[105][MAX];

void solve(){
    int n, k; cin >> n >> k;

    int sum = 0;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum < k){
        cout << 0 << "\n";
        return;
    }

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++){
        vector<ll> pref(k+1);
        pref[0] = dp[i-1][0];
        for (int j = 1; j <= k; j++){
            pref[j] = (pref[j-1] + dp[i-1][j]) % MOD;
        }
        for (int j = 0; j <= k; j++){
            int l = max(j - arr[i], 0);
            int r = j;
            if (l == 0){
                dp[i][j] = pref[r];
            }
            else {
                dp[i][j] = (pref[r] - pref[l-1] + MOD) % MOD;
            }

        }
    }


    cout << dp[n][k] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}