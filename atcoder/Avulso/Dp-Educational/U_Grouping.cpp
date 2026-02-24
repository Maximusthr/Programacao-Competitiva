#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<ll>> mat(n, vector<ll> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    vector<ll> sums((1 << n));

    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if ((i & (1 << j)) && (i & (1 << k))) sums[i] += mat[j][k];
            }
        }
    }

    vector<ll> dp((1 << n));

    // 11101
    // 11100 + sum[j] (1)

    // forma de otimização com enumerating all submasks (3^n)
    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j <= i; j++){
            if ((j & i) == j){
                dp[i] = max(dp[i], dp[i-j] + sums[j]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}