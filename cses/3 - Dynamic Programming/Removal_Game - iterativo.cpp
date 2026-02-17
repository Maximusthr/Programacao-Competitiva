#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);

    ll dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for (int l = n-1; l >= 0; l--){
        for (int r = l; r < n; r++){
            if (l == r) dp[l][r] = arr[l];
            else {
                dp[l][r] = max(arr[l] - dp[l+1][r], arr[r] - dp[l][r-1]);
            }
        }
    }

    cout << (sum + dp[0][n-1])/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}