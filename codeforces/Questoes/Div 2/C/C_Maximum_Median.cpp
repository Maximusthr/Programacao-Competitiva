#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k; 

bool ok (ll mid, vector<ll> &arr){
    ll oper = 0;

    for (int i = (n)/2; i < n; i++){
        oper += max(0LL, mid - arr[i]);
    }

    return (oper <= k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    ll l = 0, r = 2e9;
    while(l < r){
        int mid = l + (r-l + 1)/2;

        if (ok(mid, arr)){
            l = mid;
        }
        else r = mid - 1;
    }

    cout << l << "\n";
}