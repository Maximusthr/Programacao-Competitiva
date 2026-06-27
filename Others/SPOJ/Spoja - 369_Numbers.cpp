#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

ll memo[51][18][18][18];
string l, r;
ll dp(int idx = 0, int three = 0, int six = 0, int nine = 0, bool smaller = false, bool greater = false){
    if (three >= 17 || six >= 17 || nine >= 17) return 0;

    if (l.size() == idx){
        return (three > 0 && three == nine && nine == six);
    }

    auto &p = memo[idx][three][six][nine];
    if (smaller && greater){
        if (p != -1) return p % MOD;
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = r[idx] - '0';
        int y = l[idx] - '0';

        if (!smaller && i > x) continue;
        if (!greater && i < y) continue;

        bool pode = true;
        if (!smaller && i == x) pode = false;
        bool gr = true;
        if (!greater && i == y) gr = false;

        if (i == 3) ans += dp(idx+1, three + 1, six, nine, pode, gr);
        else if (i == 6) ans += dp(idx+1, three, six + 1, nine, pode, gr);
        else if (i == 9) ans += dp(idx+1, three, six, nine + 1, pode, gr);
        else ans += dp(idx+1, three, six, nine, pode, gr);
        ans %= MOD;
    }

    if (smaller && greater){
        p = ans % MOD;
    }

    return ans;
}

void solve(){
    cin >> l >> r;
    
    while(l.size() < 51){
        l = '0' + l;
    }
    while(r.size() < 51){
        r = '0' + r;
    }
    
    cout << dp() % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    memset(memo, -1, sizeof(memo));
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}