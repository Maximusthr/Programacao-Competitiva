#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [&](pair<ll, ll> x, pair<ll, ll> y){
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });

    auto ok = [&](ll mid) -> bool {
        ll aux = 0;
        for (int i = 0; i < n; i++){
            aux += v[i].first;
        }

        for (int i = 0; i < n; i++){
            ll falta = r - v[i].first;
            ll vai = min(mid, v[i].second * falta);
            ll foi = min(mid/v[i].second, falta);

            aux += foi;

            mid -= v[i].second * foi;
        }

        return (aux/n >= avg);
    };

    ll L = 0, R = 1e18;
    while (L < R){
        ll mid = L + (R-L)/2;

        if (ok(mid)){
            R = mid;
        }
        else L = mid + 1;
    }

    cout << L << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}