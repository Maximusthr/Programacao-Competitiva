#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    
    // int dp[n+1];
    // memset(dp, 0, sizeof(dp));
    // dp[0] = 0;
    
    vector<int> dp(n+1);
    dp[1] = arr[0];
    
    for (int i = 2; i <= n; i++){
        dp[i] += max(dp[i-1], dp[i-2]) + arr[i-1];
    }
    
    cout << dp[n] << "\n";
}