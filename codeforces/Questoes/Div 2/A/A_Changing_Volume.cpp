#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll a, b; cin >> a >> b;
    
    if (a > b) swap(b, a);

    int ans = 0;

    b -= a;
    
    ans += b/5;
    if (b/5 > 0) b %= 5;

    ans += b/2;

    if (b/2 > 0) b %= 2;

    ans += b;
    
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}