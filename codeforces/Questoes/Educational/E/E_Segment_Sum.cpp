#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

vector<ll> pot(20);

int k;
pair<ll, ll> memo[20][(1 << 10)][2][2];
pair<ll, ll> dp(const string &lim, int idx, int mask, bool zero, bool smaller){
    if (__builtin_popcount(mask) > k) return {0, 0};

    if (lim.size() == idx) {
        return {1, 0};
    }

    auto &p = memo[idx][mask][zero][smaller];
    if (p.first != -1) return p;  

    ll valid = 0;
    ll total = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool menor = 1;
        if (!smaller && i == x) menor = 0;

        int new_mask = 0;
        bool new_zero = zero;
        if (zero && i != 0) new_zero = false;
        if (!zero || zero && i != 0) new_mask = mask | (1 << i); 

        pair<ll, ll> ans = dp(lim, idx + 1, new_mask, new_zero, menor);
        ll qtd = ans.first;
        ll sufix = ans.second;

        valid = (valid + qtd) % MOD;

        ll sum = (i * pot[lim.size() - 1 - idx]) % MOD;
        sum = (sum * qtd) % MOD;

        total = (total + sum + sufix) % MOD;
    }

    return p = {valid, total};
}

void solve(){
    ll a, b; cin >> a >> b >> k;

    memset(memo, -1, sizeof(memo));
    ll r = dp(to_string(b), 0, 0, 1, 0).second;

    memset(memo, -1, sizeof(memo));
    ll l = dp(to_string(a-1), 0, 0, 1, 0).second;

    cout << (((r - l) % MOD) + MOD) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    pot[0] = 1;
    for (int i = 1; i <= 18; i++){
        pot[i] = (pot[i-1] * 10) % MOD;
    }

    solve();
}