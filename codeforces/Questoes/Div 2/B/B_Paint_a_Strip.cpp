#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n == 1){
        cout << 1 << "\n";
        return;
    }

    int aux = 1;
    int v = 3;
    int ans = 1;
    while (aux < n){
        aux += v;
        v <<= 1;
        ans++;
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