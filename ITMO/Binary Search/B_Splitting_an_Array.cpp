#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
ll ok_s = 0;
bool ok (ll m, vector<ll> &arr){
    ll sum = 0;
    int seg = 1;
    
    ll max_s = 0;

    for (int i = 0; i < n; i++){
        if (sum + arr[i] > m){
            seg++;
            sum = arr[i];
        }
        else sum += arr[i];
        max_s = max(max_s, sum);
    }
    
    if (seg <= k) ok_s = max_s;
    return (seg <= k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll l = 0, r = 2e15+1;
    ll ans = 0;
    while(l <= r){
        ll mid = l + (r-l)/2;

        if (ok(mid, arr)){
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }

    //cout << ans << "\n";
    cout << ok_s << "\n";
}
