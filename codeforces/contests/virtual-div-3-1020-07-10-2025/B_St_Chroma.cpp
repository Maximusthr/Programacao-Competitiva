#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x; cin >> n >> x;

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);

    if (x >= n){
        x = n-1;
    }
    swap(arr[x], arr[n-1]);

    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}