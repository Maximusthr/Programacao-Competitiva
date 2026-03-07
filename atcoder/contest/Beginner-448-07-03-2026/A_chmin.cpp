#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x; cin >> n >> x;

    for (int i = 0; i < n; i++){
        int v; cin >> v;

        if (v < x) {
            x = v;
            cout << 1 << "\n";
        }
        else cout << 0 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}