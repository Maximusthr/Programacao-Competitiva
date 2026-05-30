#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct item {
    ll l, r, c;
};

void solve(){
    int n; cin >> n;

    item all = {0, -1, INF}, left = {INF, -1, 0}, right = {-1, -INF, 0};
    while(n--){
        ll l, r, c; cin >> l >> r >> c;

        ll todo = r - l + 1;
        ll best = all.r - all.l + 1;

        if (todo > best || (todo == best && c < all.c)){
            all = {l, r, c};
        }

        if (l <= left.l){
            if (left.l == l) left.c = min(left.c, c);
            else left = {l, r, c};
        }
        if (r >= right.r){
            if (right.r == r) right.c = min(right.c, c);
            else right = {l, r, c};
        }

        ll ans = left.c + right.c;
        if (all.r >= right.r && all.l <= left.l){
            ans = min(ans, all.c);
        }

        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}