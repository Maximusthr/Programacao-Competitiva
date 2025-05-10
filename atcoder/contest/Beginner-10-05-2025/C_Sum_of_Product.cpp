#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    ll sub = 0;
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        sub += arr[i];
        ans += arr[i] * (sum - sub);
    }
    cout << ans << "\n";
}