#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<ll> seg;

    Seg (int n) : seg(4*n) {}

    ll update(int a, int b, ll v, int p, int l, int r){
        if (b < l || a > r) return seg[p];
        if (l >= a && r <= b) return seg[p] += v;
        int mid = (l+r)/2;
        return update(a, b, v, 2*p, l, mid) + update(a, b, v, 2*p+1, mid+1, r);
    }

    ll query(int idx, int p, int l, int r){
        if (l > idx || r < idx) return 0;
        if (l == r) return seg[p];
        int mid = (l+r)/2;
        return seg[p] + query(idx, 2*p, l, mid) + query(idx, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    Seg seg(n);
    for (int i = 1; i <= n; i++){
        seg.update(i, i, arr[i], 1, 1, n);
    }
    while(q--){
        int x; cin >> x;
        if (x == 1){
            int l, r; cin >> l >> r;
            ll v; cin >> v;
            seg.update(l, r, v, 1, 1, n);
        }
        else {
            int idx; cin >> idx;
            cout << seg.query(idx, 1, 1, n) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}