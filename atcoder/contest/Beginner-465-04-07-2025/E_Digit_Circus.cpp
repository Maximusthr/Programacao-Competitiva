#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

const int MOD = 998244353;

ll memo[505][(1 << 10)][2][3][2][2];
ll dp(const string &lim, int idx, int mask, bool tem, int div, bool zero, bool smaller){
    if (idx == lim.size()){
        if (zero) return 0;
        int x = (__builtin_popcount(mask) == 3);
        int y = tem;
        int z = (div == 0);
        return (x + y + z == 1);
    }

    auto &p = memo[idx][mask][tem][div][zero][smaller];
    if (p != -1) return p;

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = true;
        if (!smaller && i == x) pode = false;

        int new_mask = 0, tres = 0, multi = 0;
        bool zer = zero;
        if ((zero && i > 0) || !zer) {
            zer = false;
            new_mask = (mask | (1 << i));
            tres = (tem | (i == 3));
            multi = (div * 10 + i) % 3;
        }

        ans += dp(lim, idx+1, new_mask, tres, multi, zer, pode);
        ans %= MOD;
    }
    return p = ans;
}

void solve(){
    string s; cin >> s;

    memset(memo, -1, sizeof(memo));

    cout << dp(s, 0, 0, 0, 0, 1, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}