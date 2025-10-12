#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    double a, b, c, d; cin >> a >> b >> c >> d;

    double ans = 0;
    double p = a/b, q = 1 - p, e = 1 - c/d;

    for (int i = 0; i < 100000; i++){
        ans += p;
        p *= q*e;
    }

    cout << fixed << setprecision(10);
    cout << ans << "\n";
}