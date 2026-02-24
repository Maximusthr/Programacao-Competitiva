#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg_min {
    vector<pair<int, int>> seg;

    Seg_min(int n) : seg(4*n) {}

    pair<int, int> merge(pair<int, int> a, pair<int, int> b){
        if (a.first == b.first) {
            return {a.first, a.second + b.second};
        }

        if (a.first > b.first) return {b.first, b.second};
        return {a.first, a.second};
    }

    pair<int, int> build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = {arr[l], 1};

        int mid = (l+r) >> 1;

        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    pair<int, int> query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return {INF, INF};
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r) >> 1;

        return merge(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }
};

struct Seg_gcd {
    vector<int> seg;

    Seg_gcd(int n) : seg(4*n) {}

    int build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];

        int mid = (l+r) >> 1;

        return seg[p] = __gcd(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r) >> 1;

        return __gcd(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg_min seg(n);
    seg.build(arr, 1, 0, n-1);

    Seg_gcd seg_g(n);
    seg_g.build(arr, 1, 0, n-1);

    int q; cin >> q;

    while(q--){
        int x, y; cin >> x >> y;
        x--, y--;

        pair<int, int> menor = seg.query(x, y, 1, 0, n-1);
        int gcdd = seg_g.query(x, y, 1, 0, n-1);

        if (gcdd % menor.first == 0) cout << y - x + 1 - menor.second << "\n";
        else cout << y - x + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}