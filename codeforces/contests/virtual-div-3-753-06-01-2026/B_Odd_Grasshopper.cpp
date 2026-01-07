#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x, n; cin >> x >> n;

    int v = (n+3) % 4;
    if (x % 2 == 0){
        if (v == 0) x = x - n;
        else if (v == 1) x = x + n - (n-1);
        else if (v == 2) x = x + n + (n-1) - (n-2);
        // else x = x + (-n + (n-1) + (n-2) - (n-3));
    }
    else {
        if (v == 0) x = x + n;
        else if (v == 1) x = x - n + (n-1);
        else if (v == 2) x = x - n - (n-1) + (n-2);
        // else x = x + (n - (n-1) - (n-2) + (n-3));
    }

    cout << x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}