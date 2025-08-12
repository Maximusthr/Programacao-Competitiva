#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> moedas;

int valor[1000010];
bool ok[1000010];

int dp(int x){
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ok[x]) return valor[x];

    int best = INF;
    for (auto &c : moedas) best = min(best, dp(x - c) + 1);

    ok[x] = true;
    valor[x] = best;
    return best;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, x; cin >> n >> x;

    moedas.resize(n);
    memset(ok, false, sizeof(ok));

    for (auto &i : moedas) cin >> i;

    if (dp(x) == INF) cout << -1 << "\n";
    else cout << dp(x) << "\n";
}