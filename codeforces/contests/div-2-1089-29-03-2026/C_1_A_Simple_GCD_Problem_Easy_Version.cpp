#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    int n; cin >> n;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<ll> b(n);
    for (auto &i : b) cin >> i;

    int ans = 0;

    ll first = __gcd(arr[0], arr[1]);
    if (arr[0] > first) {
        arr[0] = first;
        ans++;
    }
    ll sec = __gcd(arr[n-1], arr[n-2]);
    if (arr[n-1] > sec){
        arr[n-1] = sec;
        ans++;
    }

    for (int i = 1; i < n-1; i++){
        ll left = __gcd(arr[i], arr[i-1]);
        ll right = __gcd(arr[i], arr[i+1]);

        if (arr[i] == left || arr[i] == right) continue;

        if (left == right){
            arr[i] = left;
            ans++;
        } else {
            ll v = lcm(left, right);

            if (v == arr[i]) continue;

            if (__gcd(left, right) == 1){
                arr[i] = v;
                ans++;
            }
            else{
                arr[i] = v;
                ans++;
            }
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