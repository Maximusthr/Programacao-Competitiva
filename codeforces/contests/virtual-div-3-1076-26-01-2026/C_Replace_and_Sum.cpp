#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = 0; i < n; i++){
        a[i] = max(a[i], b[i]);
    }

    for (int i = n-2; i >= 0; i--){
        a[i] = max(a[i], a[i+1]);
    }

    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + a[i-1];
    }

    while(q--){
        int l, r; cin >> l >> r;

        cout << prefix[r] - prefix[l-1] << " ";
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