#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = n-1; i >= 0; i--){
        if (a[i] == b[i]) continue;
        if (a[i] < b[i]) a[i] = b[i];
        else if (a[i] > b[i]){
            if (i == 0){
                cout << "NO" << "\n";
                return;
            }
            a[i-1] += (a[i] - b[i]);
            a[i] = b[i];
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] != b[i]) {
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