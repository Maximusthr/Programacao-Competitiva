#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int d;

ll memo[10005][101][2][2];
ll dp(const string &lim, int idx, int sum, bool smaller, bool dif){
    int sz = lim.size();

    if (sz == idx){
        return (sum == 0 && dif);
    }

    auto &p = memo[idx][sum][smaller][dif];
    if (p != -1) return p;

    int ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = 1;
        if (!smaller && i == x) pode = 0;

        bool ok = dif;
        if (!ok && i > 0) ok = 1;

        ans += dp(lim, idx+1, (sum + i) % d, pode, ok);
        ans %= MOD;
    }

    return p = (ans % MOD);
}

void solve(){
    string s; cin >> s;
    cin >> d;

    memset(memo, -1, sizeof(memo));

    cout << dp(s, 0, 0, 0, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}