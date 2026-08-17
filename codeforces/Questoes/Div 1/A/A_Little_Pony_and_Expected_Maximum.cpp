#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int m, n; cin >> m >> n;

    double ans = 0;
    for (int i = 1; i <= m; i++){
        double x = (double)i/(double)m;
        double y = (double)(i-1)/(double)m;

        ans += (pow(x, n) - pow(y, n))*i;
    }

    cout << fixed << setprecision(10);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
