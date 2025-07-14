#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<string, string>> pares;
    for (int i = 0; i < n; i++){
        string a, b; cin >> a >> b;

        a = a.substr(0, 2);
        pares.push_back({a, b});
    }

    map<string, int> vis;
    ll ans = 0;
    for (auto &[x, y] : pares){
        if (x != y) ans += vis[y + x];
        vis[x + y]++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    solve();
}