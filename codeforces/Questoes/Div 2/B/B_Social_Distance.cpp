#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    if (n >= m){
        cout << "NO" << "\n";
        return;
    }

    ll sum = 0;
    ll menor = INF;
    ll maior = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        maior = max(maior, arr[i]);
        menor = min(menor, arr[i]);
    }

    if (sum-menor+maior+n > m) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}