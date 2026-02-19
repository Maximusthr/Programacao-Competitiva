#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll dp[n+1][k+1];
    memset(dp, LINF, sizeof(dp));

    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            ll v = LINF;

            for (int qtd = 0; qtd + j <= k && i + qtd < n; qtd++){
                v = min(v, arr[i+qtd]);

                dp[i+qtd+1][j+qtd] = min(dp[i+qtd+1][j+qtd], dp[i][j] + (qtd+1)*v);
            }
        }
    }

    ll ans = LINF;
    for (int i = 0; i <= k; i++){
        ans = min(ans, dp[n][i]);
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