#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

int n, w;

ll memo[105][MAX];

vector<int> pesos;
vector<ll> valor;

ll dp(int i, int p){
    if (i >= n) {
        return 0;
    }

    if (memo[i][p] != -1) {
        return memo[i][p];
    }

    if (pesos[i] > p){
        return dp(i+1, p);
    }

    return memo[i][p] = max(valor[i] + dp(i+1, p - pesos[i]), dp(i+1, p));
}

void solve(){
    cin >> n >> w;

    pesos.resize(n);
    valor.resize(n);

    for (int i = 0; i < n; i++){
        cin >> pesos[i] >> valor[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0, w) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();

}