#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b(m);
    for (auto &i : b) cin >> i;

    sort(b.begin(), b.end());

    a[0] = min(a[0], b[0]-a[0]);

    for (int i = 1; i < n; i++){
        auto it = lower_bound(b.begin(), b.end(), a[i] + a[i-1]);

        if (it != b.end()) a[i] = min(a[i], *it - a[i]);

        if (a[i] < a[i-1] && it != b.end()) a[i] = *it - a[i];
        if (a[i] < a[i-1]){
            cout << "NO" << "\n";
            return;
        }
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