#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, l, r, k; cin >> n >> l >> r >> k;

    if (n % 2){
        cout << l << "\n";
        return;
    }
    if (n == 2){
        cout << -1 << "\n";
        return;
    }
    if (n % 2 == 0){
        int l_bits = 0;
        int r_bits = 0;
        bool foi = false;
        for (ll i = 62; i >= 0; i--){
            if (!foi && (l & (1LL << i))){
                foi = true;
            }
            if (foi){
                l_bits++;
            }
        }
        foi = false;
        for (ll i = 62; i >= 0; i--){
            if (!foi && (r & (1LL << i))){
                foi = true;
            }
            if (foi){
                r_bits++;
            }
        }
        if (r_bits == l_bits){
            cout << -1 << "\n";
            return;
        }
        else {
            if (k == n-1 || k == n){
                cout << (1LL << (l_bits)) << "\n";
            }
            else cout << l << "\n";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}