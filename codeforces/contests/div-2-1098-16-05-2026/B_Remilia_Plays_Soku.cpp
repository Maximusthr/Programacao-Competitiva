#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, x1, x2, k; cin >> n >> x1 >> x2 >> k;

    if (n == 2 || n == 3){
        cout << 1 << "\n";
        return;
    }

    if (x2 < x1) swap(x2, x1);

    cout << k + min(abs(x1 - x2), abs(x1 - x2 + n)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}