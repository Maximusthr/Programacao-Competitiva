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

    sort(arr.begin(), arr.end());

    ll ans = 0;
    ll sum = 0;
    int val = 0;
    for (int i = 0; i < n; i++){
        sum = arr[i] * (n-i);
        ll temp = ans;
        ans = max(ans, sum);
        if (temp == ans){
            continue;
        }
        else val = arr[i];
    }

    cout << ans << " " << val << "\n";
}
