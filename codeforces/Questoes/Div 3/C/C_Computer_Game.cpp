#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll k, n, a, b;

bool ok(ll mid){
    ll aux_n = n - mid;
    ll v = a * mid;
    
    ll aux_k = k - v;
    if (aux_k <= 0 || aux_n < 0) return false;

    ll v_b = aux_n * b;
    aux_k -= v_b;

    return (aux_k > 0);
}

void solve(){
    cin >> k >> n >> a >> b;

    ll l = 0, r = n;
    while (l < r){
        ll mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid - 1;
    }
    if (l == 0){
        if (k - 1ll * n * b <= 0) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}