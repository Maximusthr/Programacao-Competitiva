#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> dp(n+1);

    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i-j >= 0){
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << "\n";
}