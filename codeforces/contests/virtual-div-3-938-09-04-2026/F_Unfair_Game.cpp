#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;

    // a = 1
    // b = 2
    // c = 3
    // d = 4

    int ans = 0;
    if ((a & 1) && (b & 1) && (c & 1)){
        ans++;
    }
    ans += a/2 + b/2 + c/2 + d/2;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}