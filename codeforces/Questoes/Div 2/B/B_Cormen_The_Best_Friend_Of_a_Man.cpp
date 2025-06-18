#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1) {
        // cout <<  (arr[0] < k ? k-arr[0] : 0) << "\n";
        // cout << (arr[0] < k ? k : arr[0]) << "\n";
        // return 0;
        cout << 0 << "\n";
        cout << arr[0] << "\n";
        return 0;
    }

    int add = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] + arr[i-1] < k){
            add += k - arr[i]-arr[i-1];
            arr[i] += k-arr[i]-arr[i-1];
        }
    }

    cout << add << "\n";
    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}