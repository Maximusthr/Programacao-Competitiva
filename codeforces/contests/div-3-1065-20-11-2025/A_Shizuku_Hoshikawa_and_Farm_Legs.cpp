#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n % 2) {
        cout << 0 << "\n";
        return;
    }
    
    int ans = 0;
    while (n >= 0){
        if (n % 4 == 0) ans++;
        else if (n % 2 == 0) ans++;
        n -= 4;
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