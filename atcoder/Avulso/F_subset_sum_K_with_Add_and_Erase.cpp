#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> dp(k+1);

    dp[0] = 1;

    while(n--){
        char c;
        int num;
        cin >> c >> num;

        if (c == '+') {
            for (int i = k; i >= num; i--){
                dp[i] += dp[i - num];
                dp[i] %= MOD;
            }
        }
        else {
            for (int i = num; i <= k; i++){
                dp[i] += MOD;
                dp[i] -= dp[i - num];
                dp[i] %= MOD;
            }
        }


        cout << dp[k] << "\n";
    }
}