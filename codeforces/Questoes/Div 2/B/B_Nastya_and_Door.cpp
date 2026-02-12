#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> prefix(n+2);

    for (int i = 1; i < n-1; i++){
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            prefix[i+1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) prefix[i] += prefix[i-1];

    pair<int, int> ans = {0, 1};
    for (int i = 1; i <= n-k+1; i++){
        int v = prefix[i+k-1] - prefix[i-1];
        if (prefix[i] > prefix[i-1]) v--;
        if (prefix[i+k-1] != prefix[i+k-2]) v--;
        if (v > ans.first){
            ans.first = v;
            ans.second = i;
        }
    }

    cout << ans.first + 1 << " " << ans.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}