#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<ll> suffix(n+3);
    
    for (int i = n; i >= 0; i--){
        suffix[i] = suffix[i+1] + arr[i];
    }
    
    vector<ll> dp(n+3);
    for (int i = n; i >= 0; i--){
        dp[i] = suffix[i] - min(dp[i+1], dp[i+2]);
    }

    cout << dp[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}