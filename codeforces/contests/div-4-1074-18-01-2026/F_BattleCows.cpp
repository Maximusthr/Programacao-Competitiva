#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

struct Node {
    int v;
    int qtd;
};

struct Seg {
    vector<Node> seg;

    Seg(int n) : seg(4*n) {}

    Node merge(Node a, Node b){
        int x = a.v;
        int y = b.v;
        int qtd = a.qtd + b.qtd;
        return {x ^ y, qtd};
    }

    Node build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = {arr[l], 1};
        int mid = (l+r)/2;
        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int query(int idx, int p, int l, int r){
        if (l == r) return 0;
        int left = seg[2*p].v;
        int right = seg[2*p+1].v;
        int x = 0;
        int mid = (l+r)/2;

        if (mid >= idx){
            if (right > left){
                x += seg[2*p+1].qtd;
            }
            return x + query(idx, 2*p, l, mid);
        } else if (idx > mid){
            if (left >= right){
                x += seg[2*p].qtd;
            }
            return x + query(idx, 2*p+1, mid+1, r);
        }

        return 0;
    }

    Node update(int idx, int v, int p, int l, int r){
        if (idx > r || idx < l) return seg[p];
        if (l == r) return seg[p] = {v, 1};
        int mid = (l+r)/2;
        return seg[p] = merge(update(idx, v, 2*p, l, mid), update(idx, v, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n, q; cin >> n >> q;

    n = (1 << n);

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    while(q--){
        int x, v; cin >> x >> v;

        x--;    
        seg.update(x, v, 1, 0, n-1);

        cout << seg.query(x, 1, 0, n-1) << "\n";

        seg.update(x, arr[x], 1, 0, n-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}