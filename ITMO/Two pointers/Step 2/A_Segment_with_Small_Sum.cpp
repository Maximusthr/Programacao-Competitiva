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
    for (; r < n; r++){
        sum += arr[r];
        while (sum > k){
            sum -= arr[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }

    cout << ans << "\n";
}