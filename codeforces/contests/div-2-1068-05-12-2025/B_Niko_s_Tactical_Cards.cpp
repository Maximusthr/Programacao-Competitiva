// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    ll menor = 0, maior = 0;
    for (int i = 0; i < n; i++){
        ll prox_M = max(maior - a[i], b[i] - menor);
        ll prox_m = min(menor - a[i], b[i] - maior);

        maior = prox_M;
        menor = prox_m;
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}