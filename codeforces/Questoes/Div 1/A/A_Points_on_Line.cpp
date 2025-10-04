#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans = 0;
    for (int i = 0; i < n-2; i++){
        auto it = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();

        it--;

        ans += (it-i)*(it-i-1)/2;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}