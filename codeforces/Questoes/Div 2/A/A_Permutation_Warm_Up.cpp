#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    reverse(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += abs(arr[i]-i-1);
    }

    cout << ans/2 + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}