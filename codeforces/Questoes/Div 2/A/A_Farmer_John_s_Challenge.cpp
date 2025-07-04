#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    if (x == y) {
        for (int i = 0; i < x; i++){
            cout << 1 << " \n"[i == x-1];
        }
        return;
    }
    if (y == 1){
        for (int i = 0; i < x; i++){
            cout << i+1 << " \n"[i == x-1];
        }
        return;
    }
    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}