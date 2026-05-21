#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, a, b; cin >> n >> a >> b;

    ll ans = 0;

    bool tres = (3*a >= b);
    bool dois = (2*a >= b);
    bool um = (a >= b);

    if (tres) {
        ans += n/3 * b;
        n -= n/3 * 3;
    }
    if (dois){
        ans += n/2 * b;
        n -= n/2 * 2;
    }
    if (um) {
        ans += n*b;
        n -= n;
    }

    ans += n * a;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}