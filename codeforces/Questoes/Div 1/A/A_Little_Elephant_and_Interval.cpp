#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll memo[20][10][10][2];
ll dp(const string &lim, int idx, int f, int l, bool smaller){
    if (idx == lim.size()){
        return(f == l);
    }

    auto &p = memo[idx][f][l][smaller];
    if (p != -1) return p;

    ll ans = 0;
    bool zero = (f > 0);
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = 1;
        if (!smaller && i == x) pode = 0;

        if (!zero && i > 0) f = i;
        ans += dp(lim, idx+1, f, i, pode);
    }

    return p = ans;
}

void solve(){
    ll l, r; cin >> l >> r;

    memset(memo, -1, sizeof(memo));
    ll rr = dp(to_string(r), 0, 0, 0, 0);
    memset(memo, -1, sizeof(memo));
    ll lll = dp(to_string(l-1), 0, 0, 0, 0);

    cout << rr - lll << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}