#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {};

    int build(vector<int> &arr, int p, int l, int r, int x){
        if (l == r){
            return seg[p] = arr[l];
        }

        int mid = (l+r)/2;

        if (x == 0) return seg[p] = (build(arr, 2*p, l, mid, x^1) | build(arr, 2*p+1, mid+1, r, x^1));
        return seg[p] = (build(arr, 2*p, l, mid, x^1) ^ build(arr, 2*p+1, mid+1, r, x^1));
    }

    int query(){
        return seg[1];
    }

    int update(int idx, int v, int p, int l, int r, int x){
        if (l > idx || idx > r) return seg[p];
        if (l == r) return seg[p] = v;

        int mid = (l+r)/2;

        if (x == 0) return seg[p] = (update(idx, v, 2*p, l, mid, x^1) | update(idx, v, 2*p+1, mid+1, r, x^1));
        return seg[p] = (update(idx, v, 2*p, l, mid, x^1) ^ update(idx, v, 2*p+1, mid+1, r, x^1));
    }
};

void solve(){
    int n, q; cin >> n >> q;
    
    int z = (n + 1) % 2;

    n = (1 << n);

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1, z);

    while(q--){
        int x, v; cin >> x >> v;
        x--;

        seg.update(x, v, 1, 0, n-1, z);
        cout << seg.query() << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}