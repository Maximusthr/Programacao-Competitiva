#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

void solve(){
    int n; cin >> n;

    map<ll, ll> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        freq[x] += x;
    }

    vector<ll> dp(MAX);

    dp[1] = freq[1];
    dp[2] = freq[2];
    dp[3] = freq[3] + dp[1];

    for (int i = 4; i < MAX; i++){
        dp[i] = freq[i] + max(dp[i-2], dp[i-3]);
    }

    cout << max(dp[MAX-1], dp[MAX-2]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}