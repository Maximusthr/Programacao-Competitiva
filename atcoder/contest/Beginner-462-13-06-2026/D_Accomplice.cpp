#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

void solve(){
    ll n, d; cin >> n >> d;

    vector<ll> diff(MAX);
    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        if (y - d - x >= 0){
            diff[x]++;
            diff[y-d+1]--;
        }
    }

    for (int i = 1; i < MAX; i++){
        diff[i] += diff[i-1];
    }

    ll ans = 0;
    for (int i = 1; i < MAX; i++){
        if (diff[i] > 1){
            ans += ((diff[i] - 1) * diff[i])/2;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}