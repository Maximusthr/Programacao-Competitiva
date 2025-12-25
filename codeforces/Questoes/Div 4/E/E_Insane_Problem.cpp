#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){
    ll x = 1;
    while (b > 0){
        if (b & 1) x *= a;
        b >>= 1;
        a *= a;
    }
    return x;
}

void solve(){
    ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    ll ans = 0;

    for (int i = 0; i <= 32; i++){
        ll valor = exp(k, i);

        if (valor > INT32_MAX){
            break;
        }
        
        pair<ll, ll> par = {0, 0};

        ll l = l1, r = r1;
        while(l < r){
            ll mid = l + (r-l)/2;

            if (mid * valor >= l2) r = mid;
            else l = mid + 1;
        }

        par.first = l;

        l = l1, r = r1;
        while(l < r){
            ll mid = l + (r-l+1)/2;

            if (mid * valor <= r2) l = mid;
            else r = mid - 1;
        }   

        par.second = l;

        if (par.first * valor > r2 || par.second * valor < l2) continue;

        ans += max(par.second - par.first + 1, 0ll);
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