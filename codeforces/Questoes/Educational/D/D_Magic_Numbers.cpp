#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int m, d;
ll memo[2005][2005][2][2];
ll dp(const string &sup, const string &inf, int idx, int num, bool smaller, bool bigger){
    if (idx == sup.size()){
        return (num == 0);
    }   

    auto &p = memo[idx][num][smaller][bigger];
    if (p != -1) return p;

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = sup[idx] - '0';
        int y = inf[idx] - '0';

        if (!smaller && i > x) continue;
        if (!bigger && i < y) continue;
        
        bool pode = 1;
        if (!smaller && i == x) pode = 0;

        bool grande = 1;
        if (!bigger && i == y) grande = 0;

        if (idx & 1 && i == d) ans += dp(sup, inf, idx+1, (10 * num + i) % m, pode, grande);
        else if (idx % 2 == 0 && i != d) ans += dp(sup, inf, idx+1, (10 * num + i) % m, pode, grande);
        ans %= MOD;
    }

    return p = ans;
}

void solve(){
    cin >> m >> d;

    string a, b; cin >> a >> b;

    memset(memo, -1, sizeof(memo));

    cout << dp(b, a, 0, 0, 0, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}