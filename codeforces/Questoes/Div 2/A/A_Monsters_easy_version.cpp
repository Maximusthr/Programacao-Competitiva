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

    if (arr[0] > 1){
        ans += arr[0]-1;
        arr[0] = 1;
    }
    for (int i = 1; i < n; i++){
        if (arr[i] - arr[i-1] > 1){
            ans += arr[i]-arr[i-1]-1;
            arr[i] = arr[i-1]+1;
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