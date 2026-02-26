#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int n;
vector<vector<int>> comp;

ll memo[(1 << 21)];

ll dp(int mask){
    auto &v = memo[mask];
    int qtd = __builtin_popcount(mask);

    if (qtd == n){
        return 1;
    }

    if (v != -1) return v;

    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (comp[qtd][i]){
            if (!(mask & (1 << i))){
                ans += dp(mask | (1 << i));
                ans %= MOD;
            }
        }
    }

    return v = ans;
}

void solve(){
    cin >> n;
    comp.resize(n, vector<int> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> comp[i][j];
        }
    }

    for (int j = 0; j < (1 << 21); j++){
        memo[j] = -1;
    }

    cout << dp(0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}