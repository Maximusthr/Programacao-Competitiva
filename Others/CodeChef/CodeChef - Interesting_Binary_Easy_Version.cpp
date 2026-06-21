#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> dp(3);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;

    for (int i = 1; i < n; i++){
        vector<int> dp_prev(3, INF);

        for (int j = 0; j <= 2; j++){
            for (int k = 0; k <= 2; k++){
                if (j + arr[i] != arr[i-1] + k){
                    dp_prev[j] = min(dp_prev[j], dp[k] + j);
                }
            }
        }

        dp = dp_prev;
    }

    cout << min({dp[0], dp[1], dp[2]}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}