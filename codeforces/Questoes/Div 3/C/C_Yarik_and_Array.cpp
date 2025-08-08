#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans = arr[0];
    ll aux = arr[0];
    for (int i = 1; i < n; i++){
        if ((arr[i] % 2 && arr[i-1] % 2) || (arr[i] % 2 == 0 && arr[i-1] % 2 == 0)){
            aux = arr[i];
        }
        else aux = max(arr[i], arr[i]+aux);

        ans = max(ans, aux);
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