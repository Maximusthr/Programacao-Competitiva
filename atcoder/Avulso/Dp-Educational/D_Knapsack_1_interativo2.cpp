#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// 1D

void solve(){
    int n, w; cin >> n >> w;

    vector<int> peso(n);
    vector<ll> valor(n);
    for (int i = 0; i < n; i++){
        cin >> peso[i] >> valor[i];
    }
    
    vector<ll> dp(w+1);

    for (int i = 0; i < n; i++){
        for (int j = w; j >= peso[i]; j--){
            dp[j] = max(dp[j], valor[i] + dp[j - peso[i]]);
        }
    }

    cout << dp[w] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}