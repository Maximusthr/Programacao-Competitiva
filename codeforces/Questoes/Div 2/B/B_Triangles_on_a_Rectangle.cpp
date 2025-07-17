#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x, y; cin >> x >> y;

    // horinzontal
    vector<pair<int, int>> hor_0;
    int k; cin >> k;
    for (int i = 0; i < k; i++){
        int a; cin >> a;
        hor_0.push_back({a, 0});
    }
    vector<pair<int, int>> hor_y;
    cin >> k;
    for (int i = 0; i < k; i++){
        int a; cin >> a;
        hor_y.push_back({a, y});
    }

    // vertical
    vector<pair<int, int>> ver_0;
    cin >> k;
    for (int i = 0; i < k; i++){
        int a; cin >> a;
        ver_0.push_back({0, a});
    }
    vector<pair<int, int>> ver_x;
    cin >> k;
    for (int i = 0; i < k; i++){
        int a; cin >> a;
        ver_x.push_back({x, a});
    }

    ll dif_x = max(hor_0[hor_0.size()-1].first - hor_0[0].first, hor_y[hor_y.size()-1].first - hor_y[0].first);
    ll dif_y = max(ver_0[ver_0.size()-1].second - ver_0[0].second, ver_x[ver_x.size()-1].second - ver_x[0].second);

    cout << max(dif_x * y, dif_y * x) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}