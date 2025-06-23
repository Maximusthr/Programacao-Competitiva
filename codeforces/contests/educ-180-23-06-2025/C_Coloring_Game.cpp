//upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            auto id = lower_bound(arr.begin()+j+1, arr.end(), arr[i] + arr[j]) - arr.begin();
            auto it = upper_bound(arr.begin()+j+1, arr.end(), arr[n-1] - arr[i] - arr[j]) - arr.begin();
            ans += max(0LL, id-it);
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