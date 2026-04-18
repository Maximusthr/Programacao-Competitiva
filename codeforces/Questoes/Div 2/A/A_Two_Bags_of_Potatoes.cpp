#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int y, k, n; cin >> y >> k >> n;
    if (y == n){
        cout << -1 << "\n";
        return;
    }

    int v = y % k;
    int f = k - v;

    if (f + y > n){
        cout << -1 << "\n";
        return;
    }
    
    while (f + y <= n){
        cout << f << " ";
        f += k;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}