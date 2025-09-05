#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll k = accumulate(arr.begin(), arr.end(), 0ll)/n;

    for (int i = 0; i < n-1; i++){
        if (arr[i] < k){
            cout << "NO" << "\n";
            return;
        }
        arr[i+1] += max(0ll, arr[i] - k);
        arr[i] = k;
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}