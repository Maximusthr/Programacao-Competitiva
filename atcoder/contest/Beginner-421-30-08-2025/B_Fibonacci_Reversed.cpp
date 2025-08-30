#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n = 10;

    ll a, b; cin >> a >> b;

    ll dp[n];

    memset(dp, 0, sizeof(dp));

    dp[0] = a;
    dp[1] = b;

    for (int i = 2; i < n; i++){
        dp[i] += dp[i-1] + dp[i-2];

        ll x = 0;

        while (dp[i] > 0){
            x *= 10;
            x += dp[i] % 10;
            dp[i] /= 10;
        }

        dp[i] = x;
    }

    cout << dp[n-1] << "\n";
}