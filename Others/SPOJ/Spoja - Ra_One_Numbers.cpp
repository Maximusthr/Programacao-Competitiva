#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int memo[10][90][90][2];
int dp(const string &lim, int idx, int odd, int even, bool smaller){
    if (idx == lim.size()){
        return (even - odd == 1);
    }

    int &p = memo[idx][odd][even][smaller];
    if (p != -1) return p;

    int ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';
        if (!smaller && i > x) break;
        
        bool pode = true;
        if (!smaller && i == x) pode = false;

        if ((lim.size() - idx) % 2 == 0) ans += dp(lim, idx+1, odd, even + i, pode);
        else ans += dp(lim, idx+1, odd + i, even, pode);
    }

    return p = ans;
}

void solve(){
    int l, r; cin >> l >> r;

    memset(memo, -1, sizeof(memo));
    int right = dp(to_string(r), 0, 0, 0, 0);
    memset(memo, -1, sizeof(memo));
    int left = dp(to_string(l-1), 0, 0, 0, 0);

    cout << right - left << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}