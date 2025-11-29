// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<ll> b(n+1);
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    
    vector<ll> prefix(n+1), suff(n+1);
    prefix[1] = a[1];
    ll aux = a[1];
    for (int i = 2; i <= n; i++){
        aux = max(a[i], aux + a[i]);
        prefix[i] = aux;
    }

    suff[n] = a[n];
    aux = a[n]; 

    for (int i = n-1; i >= 1; i--){
        aux = max(a[i], aux + a[i]);
        suff[i] = aux;
    }

    ll ans = -LINF;
    for (int i = 1; i <= n; i++){
        ll curr = prefix[i] + suff[i] - a[i] + (k % 2 ? b[i] : 0);
        ans = max(ans, curr);
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