#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);
    ll maior = *max_element(arr.begin(), arr.end());

    ll l = maior, r = 1e18;

    while(l < r){
        ll mid = l + (r-l)/2;

        if (mid >= (sum + n-2)/(n-1)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}