#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ways = 0;
    int v = 0;
    bool change = true;
    for (int i = 0; i < n; i++){
        if (change) {
            v = arr[i];
            change = false;
        }
        v &= arr[i];
        if (v == 0){
            ways++;
            change = true;
        }
    }
    if (ways == 0) ways++;

    cout << ways << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}