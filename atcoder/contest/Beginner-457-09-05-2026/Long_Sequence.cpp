#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;

    vector<vector<ll>> arr(n);
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        for (int j = 0; j < x; j++){
            ll y; cin >> y;
            arr[i].push_back(y);
        }
    }

    vector<ll> seq(n);
    for (auto &i : seq) cin >> i;

    ll sum = 0;
    for (int i = 0; i < n; i++){
        sum += seq[i] * (ll)arr[i].size();
        if (k <= sum){
            ll v = seq[i] * arr[i].size();
            sum -= v;
            ll falta = k - sum;

            cout << arr[i][(falta-1) % arr[i].size()] << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}