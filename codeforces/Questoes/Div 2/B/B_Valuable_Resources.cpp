#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    ll X_max = -INF, X_min = INF, Y_max = -INF, Y_min = INF;

    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;

        X_max = max(x, X_max);
        X_min = min(x, X_min);

        Y_max = max(y, Y_max);
        Y_min = min(y, Y_min);
    }   

    // square city

    ll X = (X_max - X_min) * (X_max - X_min);
    ll Y = (Y_max - Y_min) * (Y_max - Y_min);

    cout << max(X, Y) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
