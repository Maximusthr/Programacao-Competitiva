#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
const int MOD = 1e9 + 7;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
 
    vector<int> valor(n);
    for (auto &i : valor) cin >> i;
 
    vector<int> dp(k+1);
 
    dp[0] = 1;
 
    for (int j = 0; j < n; j++){
        for (int i = 1; i <= k; i++){
            if (i - valor[j] >= 0){
                dp[i] += dp[i - valor[j]];
                dp[i] %= MOD;
            }
        }
    }
 
    cout << dp[k] << "\n";
}
