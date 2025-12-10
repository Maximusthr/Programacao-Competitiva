#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans = 1;
    for (int i = 0; i < n; i++){
        ans = lcm(ans, arr[i]);
    }

    int qtd = 0;
    vector<int> resp;
    for (int i = 0; i < n; i++){
        resp.push_back(ans/arr[i]);
        qtd += ans/arr[i];
    }

    if (qtd >= ans){
        cout << -1 << "\n";
        return;
    }

    for (auto &i : resp) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}