#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, s; cin >> n >> s;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int menor = min(abs(arr[0] - s), abs(arr[n-1] - s));

    int ans = menor + arr[n-1] - arr[0];
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}