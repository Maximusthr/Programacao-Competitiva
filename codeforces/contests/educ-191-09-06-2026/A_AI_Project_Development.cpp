#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x, y, z; cin >> n >> x >> y >> z;

    int ans = z;
    int aux = x * z;
    int nn = n - aux;


    cout << min((n+x+y-1)/(x+y), ans + (nn + x + 10 * y - 1)/(x + 10 * y)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}