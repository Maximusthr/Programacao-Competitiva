#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int l, r; cin >> l >> r;

    if (r <= 3) {
        cout << -1 << "\n";
        return;
    }

    if (l == r){
        for (int i = 2; i * i <= l; i++){
            if (l % i == 0) {
                cout << i << " " << l-i << "\n";
                return;
            }
        }
        cout << -1 << "\n";
        return;
    }

    int mid = (r%2 ? r-1 : r);

    cout << mid/2 << " " << mid/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}