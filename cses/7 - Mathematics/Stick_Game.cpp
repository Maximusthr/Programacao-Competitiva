#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(k);
    for (auto &i : arr) cin >> i;

    vector<int> dp(n+1);

    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (auto j : arr){
            if (i - j >= 0){
                dp[i] = (dp[i - j] ? 0 : 1);
                if (dp[i]) break;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (dp[i] == 0) cout << 'L' << "";
        else cout << 'W' << "";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}