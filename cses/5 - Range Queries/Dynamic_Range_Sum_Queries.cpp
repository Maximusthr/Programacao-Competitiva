#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<ll> tree;

    Seg (int n) : tree(4*n) {}

    ll build (vector<ll> &arr, int p, int l, int r){
        if (l == r) return tree[p] = arr[l];

        int mid = (l+r)/2;
        return tree[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && r <= b) return tree[p];

        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }

    ll update(int idx, ll v, int p, int l, int r){
        if (idx < l || r < idx) return tree[p];
        if (l == r) return tree[p] = v;

        int mid = (l+r)/2;
        return tree[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    while(q--){
        int x; cin >> x;
        if (x == 1){
            ll idx, v; cin >> idx >> v;
            idx--;
            
            seg.update(idx, v, 1, 0, n-1);
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;

            cout << 1ll * seg.query(l, r, 1, 0, n-1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}