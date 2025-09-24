#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x, y; cin >> n >> x >> y;

    map<pair<int, int>, int> val;

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;


        int xx = a % x;
        int yy = a % y;

        ans += val[{(x - xx) % x, yy % y}];
        val[{xx, yy}]++;
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