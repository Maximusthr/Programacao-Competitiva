#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int dp[n+1][3];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        if (arr[i-1] == 1 || arr[i-1] == 3){
            dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][2] + 1);
        }

        if (arr[i-1] == 2 || arr[i-1] == 3){
            dp[i][2] = max(dp[i-1][0] + 1, dp[i-1][1] + 1);
        }
    }

    cout << n - max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}