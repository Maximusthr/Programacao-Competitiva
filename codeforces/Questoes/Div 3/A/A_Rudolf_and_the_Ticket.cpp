#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b(m);
    for (auto &i : b) cin >> i;

    int ways = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i] + b[j] <= k) ways++;
        }
    }

    cout << ways << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}