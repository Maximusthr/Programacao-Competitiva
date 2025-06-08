// upsolve
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
int n; cin >> n;

        vector<ll> arr(n+1);
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        ll y = (2*arr[1] - arr[2])/(1+n);
        ll x = y - arr[1] + arr[2];

        if (x < 0 || y < 0){
            cout << "NO" << "\n";
            return;
        }

        for (int i = 1; i <= n; i++){
            arr[i] -= i * x;
            arr[i] -= y * (n-i+1);
        }

        bool ok = true;
        for (int i = 1; i <= n; i++){
            if (arr[i] != 0) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
