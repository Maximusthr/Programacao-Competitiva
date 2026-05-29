#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

/*
a ideia é usar bitmask para cada numero
*/

int k;
ll memo[(1 << 10)][2][2];
ll dp(const string &lim, int idx, bool zero, bool smaller){
    if (dif > k) return 0;

    if (lim.size() == idx) {
        return stoll(num);
    }

    auto &p = memo[idx][dif][zero][smaller];
    if (p != -1) return p;

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool menor = 1;
        if (!smaller && i == x) menor = 0;

        bool tem = false;
        if (zero && i == 0) tem = true;
        for (int j = 0; j < num.size(); j++){
            int xx = num[j] - '0';

            if (zero && xx == 0) continue;
            if (xx == i) {
                tem = true;
                break;
            }
        }

        if (zero && i != 0) zero = false;
        ans += dp(lim, num + to_string(i), idx + 1, dif + (!tem), zero, menor);
        ans %= MOD;
    }
    return p = ans;
}

void solve(){
    ll a, b; cin >> a >> b >> k;

    memset(memo, -1, sizeof(memo));

    ll r = dp(to_string(b), "", 0, 0, 1, 0);

    memset(memo, -1, sizeof(memo));
    ll l = dp(to_string(a-1), "", 0, 0, 1, 0);

    // cout << r << " " << l << "\n";
    cout << r - l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}