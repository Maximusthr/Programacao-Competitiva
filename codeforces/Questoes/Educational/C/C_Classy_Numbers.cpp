#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll memo[20][5][2];
ll dp(const string &lim, int idx, int qtd, bool smaller){
    if (qtd > 3) return 0;

    if (idx == lim.size()){
        return 1;
    }

    auto &p = memo[idx][qtd][smaller];
    if (p != -1) return p;

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = 1;
        if (!smaller && i == x) pode = 0;

        ans += dp(lim, idx+1, qtd + (i > 0), pode);
    }
    return p = ans;
}

void solve(){
    ll a, b; cin >> a >> b;

    memset(memo, -1, sizeof(memo));
    ll r = dp(to_string(b), 0, 0, 0);
    memset(memo, -1, sizeof(memo));
    ll l = 0;
    if (a > 0) l = dp(to_string(a-1), 0, 0, 0);

    cout << r - l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}