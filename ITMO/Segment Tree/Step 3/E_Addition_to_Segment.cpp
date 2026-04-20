#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<ll> seg;

    Seg(int n) : seg(4*n) {}

    ll update(int idx, ll v, int p, int l, int r){
        if (idx > r || idx < l) return seg[p];
        if (l == r) return seg[p] += v;

        int mid = (l+r)/2;
        return seg[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    Seg seg(n+1);

    while(q--){
        int t; cin >> t;
        if (t == 1){
            int l, r; cin >> l >> r;
            ll v; cin >> v;

            seg.update(l, v, 1, 0, n);
            seg.update(r, -v, 1, 0, n);
        }
        else {
            int idx; cin >> idx;

            cout << seg.query(0, idx, 1, 0, n) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}