#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;

    int ans = INF;

    vector<ll> fact(15);
    fact[0] = 1;
    for (int i = 1; i < 15; i++){
        fact[i] = fact[i-1] * i;
    }

    for (int i = 0; i < (1 << 15); i++){
        ll sum = 0;
        int qtd = 0;
        for (int bits = 0; bits < 15; bits++){
            if (i & (1 << bits)){
                sum += fact[bits];
                qtd++;
            }
        }
        ll aux = n - sum;
        if (aux < 0) continue;

        qtd += __builtin_popcountll(aux);

        ans = min(ans, qtd);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}