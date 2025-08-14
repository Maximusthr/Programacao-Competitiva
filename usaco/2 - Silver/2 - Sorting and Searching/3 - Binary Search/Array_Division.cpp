#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<ll> arr(n);

bool ok(ll mid){
    ll sum = 0;
    int seg = 1;

    for (int i = 0; i < n; i++){
        if (arr[i] > mid) return false;
        if (sum + arr[i] > mid){
            seg++;
            sum = arr[i];
        }
        else sum += arr[i];
    }

    return seg <= k;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;
    arr.resize(n);

    for (auto &i : arr) cin >> i;

    ll l = 0, r = 2e18;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l << "\n";
}
