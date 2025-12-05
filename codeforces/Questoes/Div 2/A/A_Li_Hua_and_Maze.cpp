#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    if ((x1 == y1 && x1 == 1) || (x1 == n && y1 == m) || (x1 == 1 && y1 == m) || (x1 == n && y1 == 1)){
        cout << 2 << "\n";
        return;
    }
    if ((x2 == y2 && x2 == 1) || (x2 == n && y2 == m) || (x2 == 1 && y2 == m) || (x2 == n && y2 == 1)){
        cout << 2 << "\n";
        return;
    }
    if ((x1 == 1 || y1 == 1 || x1 == n || y1 == m)){
        cout << 3 << "\n";
        return;
    }
    if ((x2 == 1 || y2 == 1 || x2 == n || y2 == m)){
        cout << 3 << "\n";
        return;
    }
    cout << 4 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}