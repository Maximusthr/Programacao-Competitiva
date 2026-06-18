#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int> ());

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (sum == k){
            cout << 0 << "\n";
            return;
        }
        if (sum > k) {
            sum -= arr[i];
            break;
        }
    }

    cout << k - sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}