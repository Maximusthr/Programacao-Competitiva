#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = unique(arr.begin(), arr.end()) - arr.begin();

    for (int i = 0; i < n; i++){
        if (i + 2 == n) break;

        if (arr[i+1] > arr[i] && arr[i+2] > arr[i+1]) ans--;
        if (arr[i] > arr[i+1] && arr[i+1] > arr[i+2]) ans--;
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