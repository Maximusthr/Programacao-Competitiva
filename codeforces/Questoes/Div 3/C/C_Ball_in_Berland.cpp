#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, k; cin >> a >> b >> k;

    vector<int> boys(a+1);
    vector<int> girls(b+1);
    //map<pair<int, int>, int> mapa;

    vector<pair<int, int>> par(k);
    for (int i = 0; i < k; i++) cin >> par[i].first;
    for (int i = 0; i < k; i++) cin >> par[i].second;

    for (int i = 0; i < k; i++){
        //mapa[par[i]]++;
        boys[par[i].first]++;
        girls[par[i].second]++;
    }

    ll ans = 0;
    for (int i = 0; i < k; i++){
        ans += 1ll * (k - boys[par[i].first] - girls[par[i].second] + 1);
    }

    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}