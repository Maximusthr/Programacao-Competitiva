#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, d; cin >> n >> d;
    
    vector<pair<int, ll>> fri;

    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;

        fri.push_back({x, y});
    }

    sort(fri.begin(), fri.end(), [&](pair<int, ll> &x, pair<int, ll> &y){
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    ll ans = fri[0].second; 
    ll aux = fri[0].second;

    int l = 0, r = 1;
    while(r < n){
        while(r < n && fri[r].first - fri[l].first < d){
            aux += fri[r].second;
            ans = max(ans, aux);
            r++;
        }

        while (r < n && l < r && fri[r].first - fri[l].first >= d){
            aux -= fri[l].second;
            l++;
        }
    }

    cout << ans << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}