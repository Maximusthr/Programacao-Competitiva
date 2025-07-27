#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> b(n);
    for (auto &i : b) cin >> i;

    ll v = (b[0]*2)-1;
    int idx = 0;
    for (int i = 1; i < n; i++){
        if (b[i] > v) {
            cout << "NO" << "\n";
            return;
        }
        else if (b[i] < b[idx]){
            v = (b[i]*2) - 1;
            idx = i;
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
