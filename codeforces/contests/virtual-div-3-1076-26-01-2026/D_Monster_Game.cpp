#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    sort(a.begin(), a.end());

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + b[i-1];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int alvo = a[i];
        int qtd = lower_bound(a.begin(), a.end(), alvo) - a.begin();
        qtd = n - qtd;

        int rounds = lower_bound(prefix.begin()+1, prefix.end(), qtd) - prefix.begin();

        if (prefix[rounds] > qtd) rounds--;

        ans = max(ans, 1ll * alvo * rounds);
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