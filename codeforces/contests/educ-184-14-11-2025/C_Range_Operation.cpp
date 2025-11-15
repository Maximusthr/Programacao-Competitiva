// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + arr[i];
    }

    vector<ll> menor(n+1);
    for (ll i = 1; i <= n; i++){
        menor[i] = max(menor[i-1], 1ll * prefix[i-1] + i - i * i);
    }

    vector<ll> maior(n+1);
    for (ll j = 1; j <= n; j++){
        maior[j] = 1ll * j * j + j - prefix[j];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, prefix[n] + maior[i] + menor[i]);
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