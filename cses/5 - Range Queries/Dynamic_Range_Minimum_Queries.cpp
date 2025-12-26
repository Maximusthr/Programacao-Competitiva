#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {}

    int build(vector<int> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];
        int mid = (l+r)/2;
        return seg[p] = min(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r){
        if (b < l || r < a) return INF;
        if (l >= a && r <= b) return seg[p];

        int mid = (l+r)/2;

        return min(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }

    int update(int i, int x, int p, int l, int r){
        if (i < l || r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int mid = (l+r)/2;

        return seg[p] = min(update(i, x, 2*p, l, mid), update(i, x, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n, m; cin >> n >> m;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    while(m--){
        int x, y, z; cin >> x >> y >> z;
        if (x == 1){
            y--;
            seg.update(y, z, 1, 0, n-1);
        }
        else {
            y--, z--;
            cout << seg.query(y, z, 1, 0, n-1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}