#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {}

    int build(int v, int p, int l, int r){
        if (l == r) return seg[p] = v;
        int mid = (l+r)/2;
        return seg[p] = min(build(v, 2*p, l, mid), build(v, 2*p+1, mid+1, r));
    }

    int update(int a, int b, int v, int p, int l, int r){
        if (a > r || b < l || seg[p] != 0) return seg[p];
        if (l == r){
            if (l == v-1 || seg[p] != 0) return seg[p];
            return seg[p] = v;
        } 
        int mid = (l+r)/2;
        return seg[p] = min(update(a, b, v, 2*p, l, mid), update(a, b, v, 2*p+1, mid+1, r));
    }

    int query (int idx, int p, int l, int r){
        if (l > idx || r < idx) return 0;
        if (l == r) return seg[p];
        int mid = (l+r)/2;

        return max(query(idx, 2*p, l, mid), query(idx, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n, q; cin >> n >> q;

    Seg seg(n);
    seg.build(0, 1, 0, n-1);

    while(q--){
        int l, r, x; cin >> l >> r >> x;
        l--, r--;

        seg.update(l, r, x, 1, 0, n-1);
    }

    for (int i = 0; i < n; i++){
        cout << seg.query(i, 1, 0, n-1) << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}