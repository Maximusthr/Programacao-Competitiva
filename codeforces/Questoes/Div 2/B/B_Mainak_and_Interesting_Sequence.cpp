#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m; cin >> n >> m;

    if ((n > m) || (m%2 == 1 && n % 2 == 0)) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";

    if (n%2) {
        for (int i = 0; i < n-1; i++){
            cout << 1 << " ";
        }
        cout << m - n + 1;
    }
    else {
        if (m % 2 == 0){
            cout << (m - (n-2))/2 << " " << (m - (n-2))/2 << " ";
            for (int i = 0; i < n - 2; i++){
                cout << 1 << " ";
            }
        }
    }

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
