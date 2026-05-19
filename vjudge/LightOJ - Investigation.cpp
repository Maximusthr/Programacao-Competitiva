#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int k;
int c = 1;

int memo[11][100][100][2];

int dp(const string &lim, int idx, int num, int sum, bool smaller){
    int sz = (int) lim.size();

    if (idx == sz){
        return (sum % k == 0 && num == 0);
    }

    auto &p = memo[idx][num][sum][smaller];
    if (p != -1) return p;

    int ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (i > x && !smaller) break;

        bool pode = 1;
        if (i == x && !smaller) pode = 0;

        ans += dp(lim, idx+1, (num * 10 + i) % k, sum+i, pode);
    }

    return p = ans;
}

void solve(){
    int l, r; cin >> l >> r >> k;
    
    
    cout << "Case " << c++ << ": ";
    if (k <= 100){
        memset(memo, -1, sizeof(memo));
        int x = dp(to_string(r), 0, 0, 0, 0);
        memset(memo, -1, sizeof(memo));
        int y = dp(to_string(l-1), 0, 0, 0, 0);
        
        cout << x - y << "\n";
    }
    else cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}