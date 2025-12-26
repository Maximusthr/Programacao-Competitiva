#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<pair<int, int>> seg;

    Seg (int n) : seg(4*n) {}

    pair<int, int> merge(pair<int, int> a, pair<int, int> b){
        if (a.first > b.first) return {b.first, b.second};
        if (a.first < b.first) return {a.first, a.second};

        return {a.first, a.second + b.second};
    }

    pair<int, int> build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = {arr[l], 1};

        int mid = (l+r)/2;
        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    pair<int, int> query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return {INF, 0};
        if (a <= l && r <= b) return seg[p];
        
        int mid = (l+r)/2;
        return merge(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }

    pair<int, int> update(int idx, int v, int p, int l, int r){
        if (l > idx || idx > r) return seg[p];
        if (l == r) return seg[p] = {v, 1};

        int mid = (l+r)/2;
        return seg[p] = merge(update(idx, v, 2*p, l, mid), update(idx, v, 2*p+1, mid+1, r));
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
            int idx, v; cin >> idx >> v;

            seg.update(idx, v, 1, 0, n-1);
        }
        else {
            int l, r; cin >> l >> r;
            r--;

            pair<int, int> ans = seg.query(l, r, 1, 0, n-1);

            cout << ans.first << " " << ans.second << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}