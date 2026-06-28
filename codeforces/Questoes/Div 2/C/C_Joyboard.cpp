#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    if (k == 1){
        cout << 1 << "\n";
        return;
    }
    if (k == 2){
        if (m < n){
            cout << m << "\n";
        }
        else cout << n + m/n - 1 << "\n";
        return;
    }
    if (k == 3){
        if (m <= n) cout << 0 << "\n";
        else cout << m - n - (m-n)/n << "\n";
        return;
    }
    if (k > 3 || m == 0){
        cout << 0 << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}