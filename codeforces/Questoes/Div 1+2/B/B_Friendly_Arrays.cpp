#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int x = 0;
    for (int i = 0; i < m; i++){
        x = (x | b[i]);
    }

    int y = 0;
    int z = 0;

    for (int i = 0; i < n; i++){
        y = (y ^ a[i]);
        z = (z ^ (x | a[i]));
    }

    cout << min(y, z) << " " << max(y, z) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}