#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5005;

ll memo[MAX][MAX][2];

ll dp(vector<int> &arr, int l, int r, bool vez){
    if (l > r) return 0;
    if (memo[l][r][vez] != INF) return memo[l][r][vez];

    ll ans = 0;

    if (vez){
        ans = max(arr[l] + dp(arr, l+1, r, !vez), arr[r] + dp(arr, l, r-1, !vez));
    }
    else {
        ans = min(dp(arr, l+1, r, !vez), dp(arr, l, r-1, !vez));
    }

    return memo[l][r][vez] = ans;
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            memo[i][j][0] = INF;
            memo[i][j][1] = INF;
        }
    }

    cout << dp(arr, 0, n-1, 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}