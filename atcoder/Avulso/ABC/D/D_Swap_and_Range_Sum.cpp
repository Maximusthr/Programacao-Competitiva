#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg(int n) : seg(4*n){}

    int build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];
        int mid = (l+r)/2;
        return seg[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    int find(int idx, int p, int l, int r){
        if (idx < l || idx > r) return 0;
        if (l == r) return seg[p];
        int mid = (l+r)/2;
        return find(idx, 2*p, l, mid) + find(idx, 2*p+1, mid+1, r);
    }

    int update(int idx, int v, int p, int l, int r){
        if (idx < l || idx > r) return seg[p];
        if (l == r) return seg[p] = v;
        int mid = (l+r)/2;
        return seg[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }

    int query(int a, int b, int p, int l, int r){
        if (a > r || b < l) return 0;
        if (l >= a && r <= b) return seg[p];
        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    while(q--){
        int x; cin >> x;
        if (x == 1){
            int y; cin >> y;
            y--;
            int temp = seg.find(y+1, 1, 0, n-1); // y+1
            int temp2 = seg.find(y, 1, 0, n-1); // y
            seg.update(y, temp, 1, 0, n-1);
            seg.update(y+1, temp2, 1, 0, n-1);
        }
        else {
            int a, b; cin >> a >> b;
            a--, b--;
            cout << seg.query(a, b, 1, 0, n-1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}