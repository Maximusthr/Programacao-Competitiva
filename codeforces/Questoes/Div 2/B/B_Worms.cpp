#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++){
        prefix[i] += prefix[i-1] + arr[i];
    }

    int q; cin >> q;
    while(q--){
        ll x; cin >> x;

        ll v = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();

        cout << ++v << "\n";
    }
}