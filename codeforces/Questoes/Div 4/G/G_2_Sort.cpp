#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    int seq = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] * 2 > arr[i-1]) seq++;
        else seq = 0;
        
        if (seq == k) {
            ans++;
            seq--;
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