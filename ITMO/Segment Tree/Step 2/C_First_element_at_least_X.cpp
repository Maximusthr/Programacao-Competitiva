#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg(int n) : seg(4*n) {}

    int build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];

        int mid = (l+r)/2;
        return seg[p] = max(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int update(int idx, int v, int p, int l, int r){
        if (idx < l || idx > r) return seg[p];
        if (l == r) return seg[p] = v;

        int mid = (l+r)/2;
        return seg[p] = max(update(idx, v, 2*p, l, mid), update(idx, v, 2*p+1, mid+1, r));
    }

    int query(int x, int p, int l, int r){
        if (seg[p] < x) return -1;
        
        if (l == r) return l;
        
        int mid = (l+r)/2;
        
        if (seg[2*p] >= x) return query(x, 2*p, l, mid);
        return query(x, 2*p+1, mid+1, r);
    }

};

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    while(q--){
        int x, y; cin >> x >> y;
        if (x == 1){
            int v; cin >> v;
            seg.update(y, v, 1, 0, n-1);
        }
        else cout << seg.query(y, 1, 0, n-1) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}