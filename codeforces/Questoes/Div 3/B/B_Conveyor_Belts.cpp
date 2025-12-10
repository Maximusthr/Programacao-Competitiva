#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;

    auto ok = [&](int n, int x, int y) -> int {
        return min({x, y, n-x+1, n-y+1});
    };

    cout << abs(ok(n, x1, y1) - ok(n, x2, y2)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}