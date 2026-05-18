#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll memo[20][10][2][2];

ll dp(const string &lim, int idx, int last_digit, bool zero_esq, bool smaller){
    int sz = (int)lim.size();

    if (idx == sz) {
        return 1;
    }

    auto &p = memo[idx][last_digit][zero_esq][smaller];
    if (p != -1) return p;

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        if (i > lim[idx] - '0' && !smaller) break;
        
        bool pode = 1;
        if (i < lim[idx] - '0' && !smaller) pode = 1;
        else if (!smaller && i == lim[idx] - '0') pode = 0;

        if (zero_esq){
            if (i == 0) ans += dp(lim, idx+1, i, true, pode);
            else ans += dp(lim, idx+1, i, false, pode);
        }
        else {
            if (i == last_digit) continue;

            ans += dp(lim, idx+1, i, false, pode);
        }
    }

    return p = ans;
}

void solve(){
    ll a, b; cin >> a >> b;

    ll r = 0, l = 0;

    memset(memo, -1, sizeof(memo));

    r = dp(to_string(b), 0, 0, 1, 0);
    if (a > 0) {
        memset(memo, -1, sizeof(memo));
        l = dp(to_string(a-1), 0, 0, 1, 0);
    }

    cout << r - l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}