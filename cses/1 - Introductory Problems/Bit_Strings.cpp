#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

ll exp(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return x;
}

void solve(){
    int n; cin >> n;

    cout << exp(2, n) << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}