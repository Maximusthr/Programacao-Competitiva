#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    ll ans = 0;

    vector<ll> arr(n+1);
    vector<pair<ll, ll>> odd, even;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (i & 1) odd.push_back({arr[i], i});
        else even.push_back({arr[i], i});
    }

    sort(odd.begin(), odd.end(), greater<pair<ll, ll>> ());
    sort(even.begin(), even.end(), greater<pair<ll, ll>> ());

    vector<int> idx(m);
    for (auto &i : idx) cin >> i;

    int j = 0, k = 0;
    for (int i = 0; i < m; i++){
        if (idx[i] & 1){
            if (j == 0 && j < odd.size()){
                odd[j].second = -1;
                j++;
            }
            else {
                if (j < odd.size() && odd[j].first > 0) {
                    odd[j].second = -1;
                    j++;
                }
                else continue;
            }
        }
        else {
            if (k == 0 && k < even.size()){
                even[k].second = -1;
                k++;
            }
            else {
                if (k < even.size() && even[k].first > 0){
                    even[k].second = -1;
                    k++;
                }
                else continue;
            }
        }
    }

    for (int i = 0; i < odd.size(); i++){
        if (odd[i].second == -1) continue;
        ans += odd[i].first;
    }
    for (int i = 0; i < even.size(); i++){
        if (even[i].second == -1) continue;
        ans += even[i].first;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}