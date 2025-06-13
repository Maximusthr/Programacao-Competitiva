#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n; cin >> n;

    vector<pair<ll, ll>> arr(n);
    
    for (auto &[x, y] : arr) cin >> x >> y;

    sort(arr.begin(), arr.end(), [&](pair<ll, ll> &x, pair<ll, ll> &y){
        return x.second < y.second;
    });
    
    ll ans = 0;
    int i = 0, j = n-1;
    while(i <= j){
        int sub = min(arr[i].first, arr[j].first);

        if (i == j) sub = sub/2;

        ans = max(ans, arr[i].second + arr[j].second);
        arr[i].first -= sub;
        arr[j].first -= sub;

        if (arr[i].first == 0) i++;
        if (arr[j].first == 0) j--;
    }

    cout << ans << "\n";
}