#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

void solve(){
    int n; cin >> n;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    map<int, deque<int>> ocur;

    for (int i = 1; i <= n; i++){
        dp[i] = dp[i-1];

        int x; cin >> x;
        ocur[x].push_back(i);

        if (ocur[x].size() > x) ocur[x].pop_front();
        if (ocur[x].size() == x){
            dp[i] = max(dp[i], dp[ocur[x].front() - 1] + x);
        }
    }

    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}