#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Node {
    ll seg = 0;
    ll pref = 0;
    ll suff = 0;
    ll sum = 0;
};

struct Seg {
    vector<Node> seg;

    Seg(int n) : seg(4*n) {};

    Node merge(Node a, Node b){
        ll seg = max({a.seg, b.seg, a.suff + b.pref});
        ll pref = max({a.pref, a.sum + b.pref});
        ll suff = max({b.suff, a.suff + b.sum});
        ll sum = a.sum + b.sum;

        return {seg, pref, suff, sum};
    }

    Node build(vector<ll> &arr, int p, int l, int r){
        if (l == r){
            if (arr[l] > 0) return seg[p] = {arr[l], arr[l], arr[l], arr[l]};
            return seg[p] = {0, 0, 0, arr[l]};
        }
        int mid = (l+r)/2;
        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    Node update(int idx, ll v, int p, int l, int r){
        if (idx > r || l > idx) return seg[p];
        if (l == r){
            if (v > 0) return seg[p] = {v, v, v, v};
            return seg[p] = {0, 0, 0, v};
        }
        int mid = (l+r)/2;
        return seg[p] = merge(update(idx, v, 2*p, l, mid), update(idx, v, 2*p+1, mid+1, r));
    }

    ll query(){
        return seg[1].seg;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    cout << seg.query() << "\n";
    while(q--){
        int i, v; cin >> i >> v;
    
        seg.update(i, v, 1, 0, n-1);
        cout << seg.query() << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}