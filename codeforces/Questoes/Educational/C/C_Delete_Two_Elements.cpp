#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    
    if (sum * 2 % n != 0){
        cout << 0 << "\n";
        return;
    }

    sum = (sum * 2)/n;

    ll ans = 0;
    map<ll, int> freq;
    for (int i = 0; i < n; i++){
        ans += freq[sum-arr[i]];

        freq[arr[i]]++;
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