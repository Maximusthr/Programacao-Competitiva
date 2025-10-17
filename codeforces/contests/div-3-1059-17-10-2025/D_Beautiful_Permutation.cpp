// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int query(int type, int l, int r){
    cout << type << " " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

void solve(){
    int n; cin >> n;

    int tam = query(2, 1, n) - query(1, 1, n);
    int ans = n;

    int l = 1, r = n;
    while(l <= r){
        int mid = l + (r-l)/2;

        if (query(2, 1, mid) > query(1, 1, mid)){
            r = mid - 1;
            ans = min(mid, ans);
        }
        else l = mid + 1;
    }

    cout << "! " << l << " " << ans + tam -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}