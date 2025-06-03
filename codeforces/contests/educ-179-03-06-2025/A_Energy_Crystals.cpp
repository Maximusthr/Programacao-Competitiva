#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x; cin >> x;

    if (x == 1){
        cout << 3 << "\n";
        return;
    }

    ll ans = 3;
    int a = 1, b = 1;
    while(true){
        a *= 2;
        b = b*2 + 1;
        ans += 2;
        if (x >= a && x <= b){
            break;
        }
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