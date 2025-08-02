#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int ans = 0, s = 0, ns = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 1){
            ns++;
        }
        else {
            s += ns;
            ns = 0;
        }

        ans = max(ans, ns + (s ? s/2 + 1 : 0));
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