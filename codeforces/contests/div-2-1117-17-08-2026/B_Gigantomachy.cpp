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

    int t1 = 0;
    int t2 = 0;
    for (int i = 1; i < n; i++){
        int dif = a[i-1] - a[i] + 1;
        t1 += dif;
    }
    t1 += a.back();

    for (int i = 1; i < m; i++){
        int dif = b[i-1] - b[i] + 1;
        t2 += dif;
    }
    t2 += b.back();

    if (t1 >= t2){
        cout << 1 << "\n";
    }
    else cout << 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
