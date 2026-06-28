#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b(n);
    for (auto &i : b) cin >> i;

    vector<int> copy = a;
    sort(copy.begin(), copy.end());
    vector<int> copy2 = b;
    sort(copy2.begin(), copy2.end());

    for (int i = 0; i < n; i++){
        if (copy2[i] > copy[i]){
            cout << -1 << "\n";
            return;
        }
    }

    bool flag = false;
    for (int i = 0; i < n; i++){
        if (a[i] < b[i]) {
            flag = true;
        }
    }

    int ans = 0;
    if (flag){
        ans += m;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++){
            ans += abs(a[i] - b[i]);
        }
    }
    else {
        for (int i = 0; i < n; i++){
            ans += abs(a[i] - b[i]);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}