#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    vector<ll> todos;
    ll um = 0;
    for (auto &i : arr) {
        cin >> i;
        if (i & 1) {
            if (i == 1) um++;
            else todos.push_back(i);
        }
        else todos.push_back(i);
    }
    ll sum = accumulate(arr.begin(), arr.end(), 0ll);
    if (sum <= 2 || todos.size() == 0) {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    if (todos.size() == 1){
        ans += todos[0];

        ll x = todos[0]/2;
        ans += min(x, um);
    }
    else {
        for (int i = 0; i < todos.size(); i++){
            ans += todos[i];

            ll x = todos[i]/2 - 1;
            ans += min(x, um);
            um -= min(x, um);
        }
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