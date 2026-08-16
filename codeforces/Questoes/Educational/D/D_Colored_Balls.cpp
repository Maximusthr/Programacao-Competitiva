#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int dp[5005];
    memset(dp, 0, sizeof(dp));

    ll ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 5000; j++){
            ans = (ans + dp[j] * max(arr[i], (arr[i] + j + 1)/2)) % MOD;
        }
        for (int j = 5000 - arr[i]; j >= 0; j--){
            if (dp[j] > 0){
                dp[j + arr[i]] = (dp[j + arr[i]] + dp[j]) % MOD;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
