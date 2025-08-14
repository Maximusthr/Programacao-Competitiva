#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
const int MOD = 1e9 + 7;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, x; cin >> n >> x;
 
    vector<int> valor(n);
    for (auto &i : valor) cin >> i;
 
    vector<int> dp(x+1);
 
    dp[0] = 1;
 
    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - valor[j] >= 0){
                dp[i] += dp[i-valor[j]];
                dp[i] %= MOD;
            }
        }
    }
 
    cout << dp[x] << "\n";
}
