#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (ll k = 1; k <= 1e18; k *= 2){
        set<ll> teste;
        for (int i = 0; i < n; i++){
            teste.insert(arr[i] % k);
        }
        if (teste.size() == 2){
            cout << k << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
