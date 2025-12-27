#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);

    ll ans = -LINF;
    ll aux = 0;
    for (int i = 0; i < n; i++){
        if (i == n-1){
            continue;
        }
        
        sum -= arr[i];
        ans = max(ans, (sum * -1) + aux);

        if (i == 0) aux += arr[i];
        else aux += abs(arr[i]);
    }

    cout << max(ans, aux) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}