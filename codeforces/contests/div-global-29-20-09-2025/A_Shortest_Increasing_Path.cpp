#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    int a = x-y;
    if ((y == 1) || (x >= y) && (y+1 >= x)){
        cout << -1 << "\n";
        return;
    }
    if (x < y){
        cout << 2 << "\n";
    }
    else {
        cout << 3 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}