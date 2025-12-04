#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    reverse(arr.begin(), arr.end());

    // i+k-1

    for (int i = k-1, j = n-1; i < n && i < j; i += k, j -= k){
        swap(arr[i], arr[j]);
    }

    for (auto &i : arr) {
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
