#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;

    int ans = b-a + d-c;
    int inters = max(min(b, d) - max(a, c), 0);

    cout << ans - inters << "\n";
}
