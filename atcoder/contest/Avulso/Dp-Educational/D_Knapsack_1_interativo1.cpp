#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// 2D

void solve(){
    int n, w; cin >> n >> w;

    vector<int> peso(n);
    vector<ll> valor(n);
    for (int i = 0; i < n; i++){
        cin >> peso[i] >> valor[i];
    }
    
    vector<vector<ll>> dp(n+1, vector<ll> (w+1));

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= w; j++){
            dp[i][j] = dp[i-1][j];

            if (j >= peso[i-1]){
                dp[i][j] = max(dp[i][j], valor[i-1] + dp[i-1][j - peso[i-1]]);
            }
        }
    }

    cout << dp[n][w] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}