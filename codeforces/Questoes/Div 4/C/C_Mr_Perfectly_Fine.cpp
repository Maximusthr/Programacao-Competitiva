#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<string, int> mapa;

    for (int i = 0; i < n; i++){
        int x; string c; cin >> x >> c;

        if (mapa[c] == 0) mapa[c] = x;
        else mapa[c] = min(mapa[c], x);
    }

    int ans = INF;
    if (mapa.count("11")) ans = mapa["11"];
    if (mapa.count("01") && mapa.count("10")) ans = min(ans, mapa["01"] + mapa["10"]);

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}