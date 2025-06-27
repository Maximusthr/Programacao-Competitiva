#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    bool ok = true;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-1; i++){
        if (arr[i] >= arr[i+1]){
            ok = false;
        }
    }

    if (ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        solve();
    }
}