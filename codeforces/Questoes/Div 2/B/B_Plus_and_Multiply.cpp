#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll binpow(ll a, ll b){
    ll x = 1;
    while (b > 0){
        if (b & 1) x *= a;
        b >>= 1;
        a *= a;
    }
    return x;
}

void solve(){
    ll n, a, b; cin >> n >> a >> b;

    if (b == 1) {
        cout << "Yes" << "\n";
        return;
    }   

    for (int i = 0; i <= 100; i++){
        ll x = binpow(a, i);
        if (x > n) break;
        if (x % b == n % b){
            cout << "Yes" << "\n";
            return;
        }
    }
    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}