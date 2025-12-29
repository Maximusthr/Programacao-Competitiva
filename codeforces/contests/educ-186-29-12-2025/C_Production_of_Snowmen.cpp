#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : c) cin >> i;

    ll ans = n;
    int x = 0;
    for (int i = 0; i < n; i++){
        bool ok = true;
        for (int j = 0; j < n; j++){
            if (a[j] >= b[(i+j)%n]){
                ok = false;
                break;
            }
        }

        if (ok) x++;
    }

    int y = 0;
    for (int i = 0; i < n; i++){
        bool ok = true;
        for (int j = 0; j < n; j++){
            if (b[j] >= c[(i+j)%n]){
                ok = false;
                break;
            }
        }
        if (ok) y++;
    }

    cout << ans * x * y << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}