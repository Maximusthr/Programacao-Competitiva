#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int dp[n+1][2];
    memset(dp, INF, sizeof(dp));

    dp[0][1] = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            for (int fight = 1; fight <= min(n-i, 2); fight++){
                int hard = arr[i] + (fight > 1 ? arr[i+1] : 0);

                dp[i + fight][!j] = min(dp[i + fight][!j], dp[i][j] + j * hard);
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}