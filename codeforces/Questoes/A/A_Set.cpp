#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int l, r, k; cin >> l >> r >> k;

        int ans = (r/k)-l+1;
        if (ans < 0) cout << 0 << "\n";
        else cout << ans << "\n";
    }
}
