#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> odd;
    vector<ll> even;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 2) odd.push_back(x);
        else even.push_back(x);
    }

    sort(odd.begin(), odd.end());

    vector<ll> new_odd;
    int l = 0, r = (int)odd.size()-1;
    for (int i = 0; l < r && i < (int)odd.size(); i++){
        if (i % 2 == 0){
            new_odd.push_back(odd[r--]);
        }
        else l++;
    }

    if (odd.size() % 2) new_odd.push_back(odd[r]);

    ll ans = accumulate(new_odd.begin(), new_odd.end(), 0ll) + accumulate(even.begin(), even.end(), 0ll);

    if (new_odd.size() == 0){
        cout << 0 << "\n";
    }
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}