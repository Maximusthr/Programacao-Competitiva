#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, k;
vector<pair<ll, ll>> seq;

bool ok(ll mid){
    ll sum = 0;

    for (int i = 0; i < n; i++){
        if (seq[i].first > mid) continue;

        sum += min(mid - seq[i].first, 1ll*seq[i].second - seq[i].first + 1);
    }

    return (sum <= k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        seq.push_back({x, y});
    }

    ll l = -2e9, r = 2e9;
    while (l < r){
        ll mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid-1;
    }

    cout << l << "\n";
}