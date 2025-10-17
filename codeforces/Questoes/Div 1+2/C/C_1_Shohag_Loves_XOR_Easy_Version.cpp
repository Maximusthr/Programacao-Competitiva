#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m; cin >> n >> m;

    int ans = 0;
    int bits = 32 - __builtin_clz(n);

    int i = 1;
    while (i <= m && 32 - __builtin_clz(i) <= bits){
        if (i == n){
            i++;
            continue;
        }
        int v = (i ^ n);
        if (i % v == 0 || n % v == 0){
            ans++;
        }
        i++;
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