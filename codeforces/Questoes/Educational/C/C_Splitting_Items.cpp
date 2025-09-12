#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<ll> ());

    for (int i = 1; i < n; i += 2){
        ll v = arr[i-1] - arr[i];
        if (v >= k){
            arr[i] += k;
            k = 0;
            break;
        }
        else {
            arr[i] = arr[i-1];
            k -= v;
        }
    } 

    ll sum_even = 0, sum_odd = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            sum_even += arr[i];
        }
        else sum_odd += arr[i];
    }

    cout << sum_even - sum_odd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}