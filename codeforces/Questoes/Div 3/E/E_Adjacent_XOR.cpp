#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = 0; i < n-1; i++){
        if (a[i] == b[i]) continue;
        if (((a[i] ^ b[i+1]) == b[i]) || ((a[i] ^ a[i+1]) == b[i])){
            a[i] = b[i];
        }
        else {
            cout << "NO" << "\n";
            return;
        }
    }

    if (a[n-1] != b[n-1]){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}