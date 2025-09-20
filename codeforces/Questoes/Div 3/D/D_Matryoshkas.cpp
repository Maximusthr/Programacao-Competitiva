#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<int, int> mapa;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        mapa[x]++;
    }

    ll ans = 0;
    int v = 0;
    for (auto [x, y] : mapa){
        if (v == 0){
            v = y;
            ans += y;
            continue;
        }
        if (mapa[x-1] > 0 && y > v){
            ans += y-v;
        }
        else if (mapa[x-1] == 0) {
            ans += y;
        }
        v = y;
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