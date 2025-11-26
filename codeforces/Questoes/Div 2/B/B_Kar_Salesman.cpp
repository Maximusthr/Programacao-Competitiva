#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x; cin >> n >> x;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans_1 = (accumulate(arr.begin(), arr.end(), 0ll) + x - 1)/x;

    ll ans_2 = *max_element(arr.begin(), arr.end());

    cout << max(ans_1, ans_2) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}