#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    // ¯\_(ツ)_/¯

    string s = arr[0];
    for (int i = 1; i < n; i++){
        s = min(s + arr[i], arr[i] + s);
    }

    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}