#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// diff array

struct Seg {
    vector<ll> seg;

    Seg (int n) : seg(4*n) {}

    ll update(int idx, ll v, int p, int l, int r){
        if (idx < l || idx > r) return seg[p];
        if (l == r){
            return seg[p] += v;
        }
        int mid = (l+r)/2;
        return seg[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (l > b || r < a) return 0;
        if (a <= l && r <= b) return seg[p];
        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
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
        seg.update(i, arr[i] - arr[i-1], 1, 1, n);
    }
    while(q--){
        int x; cin >> x;
        if (x == 1){
            int l, r; cin >> l >> r;
            ll v; cin >> v;
            seg.update(l, v, 1, 1, n);
            seg.update(r+1, -v, 1, 1, n);
        }
        else {
            int idx; cin >> idx;
            cout << seg.query(1, idx, 1, 1, n) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}