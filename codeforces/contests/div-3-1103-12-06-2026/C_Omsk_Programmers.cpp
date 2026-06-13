#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, x; cin >> a >> b >> x;

    if (a == b){
        cout << 0 << "\n";
        return;
    }
    
    int ans = INF;
    int div = 0;
    while (a != b){
        ans = min(abs(a - b) + div, ans);
        if (a > b) a /= x;
        else b /= x;
        div++;
        ans = min(abs(a - b) + div, ans);
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