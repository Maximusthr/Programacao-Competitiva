#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    int x, y; cin >> x >> y;
    int v = abs(x - y);

    set<int> div;

    for (ll i = 1; i * i <= v; i++){
        if (v % i == 0){
            div.insert(v/i);
            div.insert(i);
        }
    }

    cout << (div.size() > 0 ? div.size() : 1) << "\n";
    for (int i = 0; i < x; i++){
        cout << 1 << " ";
    }
    for (int i = 0; i < y; i++){
        cout << -1 << " ";
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