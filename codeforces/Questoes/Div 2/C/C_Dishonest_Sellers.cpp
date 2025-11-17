#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<pair<ll, ll>> a(n);
    for (auto &i : a) cin >> i.first;
    for (auto &i : a) cin >> i.second;

    sort(a.begin(), a.end(), [&](pair<ll, ll> a, pair<ll, ll> b){
        return (a.first - a.second) < (b.first - b.second);
    });

    ll ans = 0;
    for (int i = 0; i < k; i++){
        ans += a[i].first;
    }
    for (int i = k; i < n; i++){
        ans += min(a[i].first, a[i].second);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}