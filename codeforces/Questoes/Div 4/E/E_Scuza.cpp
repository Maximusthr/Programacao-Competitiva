#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    vector<ll> prefix(n+1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }
    
    for (int i = 1; i < n; i++){
        arr[i] = max(arr[i], arr[i-1]);
    }
    
    while(q--){
        ll v; cin >> v;

        auto it = upper_bound(arr.begin(), arr.end(), v) - arr.begin();

        cout << prefix[it] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}