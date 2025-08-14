#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    bool ok = true;
    ll sum = -1;
    for (int i = 0; i < n-1; i++){
        if (arr[i] > arr[i+1]){
            ok = false;
            ll temp = (arr[i] + arr[i+1] + 1)/2;
            sum = max(sum, temp);
        }
    }
    if (ok) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < n; i++){
        arr[i] = abs(arr[i] - sum);
    }

    ok = true;
    for (int i = 0; i < n-1; i++){
        if (arr[i] > arr[i+1]){
            ok = false;
            break;
        }
    }
    if (ok) cout << sum << "\n";
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
   
    int t; cin >> t;
    while(t--){
        solve();
    }
}
