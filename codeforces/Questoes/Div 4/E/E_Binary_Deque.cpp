#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    int cur = 0, l = 0, maxlen = -1;
    for (int r = 0; r < n; r++){
        cur += arr[r];
        while(l <= r && cur > k){
            cur -= arr[l++];
        }
        if (cur == k){
            maxlen = max(maxlen, r - l + 1);
        }
    }

    if (maxlen == -1) cout << -1 << "\n";
    else cout << n-maxlen << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}