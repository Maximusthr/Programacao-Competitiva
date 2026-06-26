#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ok(int x, int y){
    if (x == y) return true;
    if (x % 3 != 0) return false;
    return ok(x/3, y) || ok(2*x/3, y);
}

void solve(){
    int n, m; cin >> n >> m;

    cout << (ok(n, m) ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}