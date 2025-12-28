#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n){}

    int build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];
        int mid = (l+r)/2;
        return seg[p] = max(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int update(int a, int b, int p, int l, int r){
        if (a > r || b < l || seg[p] < 10) return seg[p];
        if (l == r){
            int sum = 0;
            while (seg[p] > 0){
                sum += seg[p] % 10;
                seg[p] /= 10;
            }
            return seg[p] = sum;
        }
        int mid = (l+r)/2;
        return seg[p] = max(update(a, b, 2*p, l, mid), update(a, b, 2*p+1, mid+1, r));
    }

    int query(int idx, int p, int l, int r){
        if (r < idx || l > idx) return 0;
        if (l == r) return seg[p];
        int mid = (l+r)/2;
        return max(query(idx, 2*p, l, mid), query(idx, 2*p+1, mid+1, r));
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
            int l, r; cin >> l >> r;
            l--, r--;
            seg.update(l, r, 1, 0, n-1);
        }
        else {
            int idx; cin >> idx;
            idx--;
            cout << seg.query(idx, 1, 0, n-1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}