#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y, l, r, a, b; cin >> x >> y >> l >> r >> a >> b;

    int ans = 0;
    if (a <= l && b >= r){
        ans += (l - a) * y;
        ans += (b - r) * y;
        ans += (r - l) * x;
    }
    else if ((a < l && b <= l) || (a >= r && b > r)){
        ans += (b - a) * y;
    }
    else if (a >= l && b >= r){
        ans += (b - r) * y;
        ans += (r - a) * x;
    }
    else if (a >= l && b <= r){
        ans += (b - a) * x;
    }
    else if (a <= l && b <= r){
        ans += (b - l) * x;
        ans += (l - a) * y;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}