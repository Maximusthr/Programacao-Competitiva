#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    ll n, f; cin >> n >> f;

    ll ans = 0;
    vector<ll> arr;
    for (int i = 0; i < n; i++){
        int k, l; cin >> k >> l;

        ll sales = min(k, l);
        ans += sales;

        ll new_sales = min(k*2, l);
        arr.push_back({new_sales - sales});
    }

    sort(arr.rbegin(), arr.rend());


    for (int i = 0; i < f; i++){
        ans += arr[i];
    }

    cout << ans << "\n";
}
