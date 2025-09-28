#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<pair<ll, ll>> vec;
    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        vec.push_back({x, y});
    }

    ll ans = 0;
    ll dif = 0;

    for (int i = 0; i < n; i++){
        if (i == 0){
            dif = vec[0].first;

            if (dif % 2){
                if (vec[0].second == 0){
                    ans += dif-1;
                }
                else ans += dif;
            }
            else {
                if (vec[0].second == 0){
                    ans += dif;
                }
                else ans += dif-1;
            }
        }
        else {
            dif = vec[i].first - vec[i-1].first;
            bool ant = (vec[i].second == vec[i-1].second);
            if (dif % 2){
                if (ant){
                    ans += dif-1;
                }
                else ans += dif;
            }
            else {
                if (ant){
                    ans += dif;
                }
                else ans += dif-1;
            }
        }
    }
    dif = m - vec[vec.size()-1].first;
    ans += dif;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}