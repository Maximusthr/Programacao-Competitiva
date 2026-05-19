#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll memo[11][100][2];
ll dp(const string &lim, int idx, ll sum, bool smaller){
    int sz = (lim.size());
    if (idx == sz) return sum;

    auto &p = memo[idx][sum][smaller];
    if (p != -1) return p;

    ll ret = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = 1;
        if (!smaller && i == x) pode = 0;

        ret += dp(lim, idx+1, sum + i, pode);
    }

    return p = ret;
}

void solve(){
    int a, b;

    while(cin >> a >> b){
        if (a == -1 && b == -1) break;

        ll r, l;

        memset(memo, -1, sizeof(memo));
        r = dp(to_string(b), 0, 0, 0);

        memset(memo, -1, sizeof(memo));
        if (a > 0) l = dp(to_string(a-1), 0, 0, 0);
        
        cout << r - l << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}