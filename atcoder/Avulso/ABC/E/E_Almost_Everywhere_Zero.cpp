#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int k;

ll memo[105][4][2];
ll dp(const string &lim, int idx, int qtd, bool smaller){
    if (qtd > k) return 0;

    if (idx == lim.size()){
        return (qtd == k);
    }

    auto &p = memo[idx][qtd][smaller];
    if (p != -1) return p;

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = 1;
        if (i == x && !smaller) pode = 0;

        ans += dp(lim, idx+1, qtd + (i != 0), pode);
    }
    return p = ans;
}

void solve(){
    string s; cin >> s;
    cin >> k;

    memset(memo, -1, sizeof(memo));

    cout << dp(s, 0, 0, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}