#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = 0, l = 0, r = 0;
    ll ans = 0;
    for (int l = 0; l < n; l++){
        while(r < n && sum < k){
            sum += arr[r];
            r++;
        }
        if (sum >= k){
            ans += n-r+1;
        }
        sum -= arr[l];
    }

    cout << ans << "\n";
}