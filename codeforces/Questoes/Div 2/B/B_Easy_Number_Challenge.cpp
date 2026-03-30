#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;
const int MOD = 1073741824;

void solve(){
    int a, b, c; cin >> a >> b >> c;

    vector<ll> div(MAX);
    for (ll i = 1; i < MAX; i++){
        for (ll j = i; j < MAX; j += i){
            div[j]++;
        }
    }

    ll ans = 0;

    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            for (int k = 1; k <= c; k++){
                ans = (ans + div[i*j*k]) % MOD;
            }
        }
    }

    cout << ans % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}