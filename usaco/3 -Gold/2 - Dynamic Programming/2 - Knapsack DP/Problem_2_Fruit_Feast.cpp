#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    vector<array<bool, 2>> dp(n+1);

    // dp[x][0] = sem agua
    // dp[x][1] = com agua -> peso/2

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++){
        if (dp[i][0]){
            if (i + a <= n){
                dp[i + a][0] = 1;
            }
            if (i + b <= n){
                dp[i + b][0] = 1;
            }
            dp[i/2][1] = 1;
        }
    }

    for (int i = 0; i <= n; i++){
        if (dp[i][1]){
            if (i + a <= n){
                dp[i + a][1] = 1;
            }
            if (i + b <= n){
                dp[i + b][1] = 1;
            }
        }
    }

    for (int i = n; i >= 0; i--){
        if (dp[i][0] || dp[i][1]) {
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    solve();
}