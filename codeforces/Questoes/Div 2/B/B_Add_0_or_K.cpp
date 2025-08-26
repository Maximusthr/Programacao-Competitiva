#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 2; ; i++){ // 29
        if (__gcd(i, k) != 1) continue;

        for (auto &v : arr){
            while (v % i != 0){
                v += k;
            }
        }
        break;
    }

    for (auto v : arr) cout << v << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}