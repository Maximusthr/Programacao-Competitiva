#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int ans = 0;
    while (true){
        bool ok = false;
        for (int j = 0; j < n; j++){
            if ((!ok) && a[j] > b[j]){
                a[j]--;
                ok = true;
            }
            else if (a[j] < b[j]){
                a[j]++;
            }
        }
        ans++;
        if (!ok) {
            break;
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