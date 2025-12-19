#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int l, a, b; cin >> l >> a >> b;

    int ans = 0;
    int v = a;
    for (int i = 0; i <= 5000; i++){
        v = (a + i*b) % l;
        ans = max(ans, v);
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