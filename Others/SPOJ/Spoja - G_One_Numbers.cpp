#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6;
vector<bool> crivo(MAX, true);

int memo[10][100][2];
int dp(const string &lim, int idx, int sum, bool smaller){
    if (lim.size() == idx){
        return crivo[sum];
    }

    auto &p = memo[idx][sum][smaller];
    if (p != -1) return p;

    int ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;

        bool pode = true;
        if (!smaller && i == x) pode = false;
        ans += dp(lim ,idx+1, sum + i, pode);
    }

    return p = ans;
}

void solve(){
    int l, r; cin >> l >> r;

    memset(memo, -1, sizeof(memo));
    int rr = dp(to_string(r), 0, 0, 0);
    memset(memo, -1, sizeof(memo));
    int ll = dp(to_string(l-1), 0, 0, 0);
    
    cout << rr - ll << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo[0] = 0;
    crivo[1] = 0;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}