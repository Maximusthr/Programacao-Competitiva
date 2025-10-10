// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<ll> odd;
    vector<ll> even;

    ll lado = 0;
    for (auto [x, y] : freq){
        lado += x * (y/2);

        if (y % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    if (lado == 0){
        cout << 0 << "\n";
        return;
    }
    
    // 1 embaixo
    ll ans = 0;
    for (auto i : odd){
        if (2 * lado > i){
            ans = max(ans, 2 * lado + i);
        }
    }

    // 1 embaixo e 1 em cima
    for (int i = 1; i < odd.size(); i++){
        if (odd[i-1] + 2 * lado > odd[i]){
            ans = max(ans, odd[i-1] + odd[i] + 2 * lado);
        }
    }

    // apenas pares
    for (auto i : even){
        if (lado > i){
            ans = max(ans, 2 * lado);
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