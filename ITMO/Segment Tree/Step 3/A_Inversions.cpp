#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg{
    int n;
    vector<int> seg;

    Seg (int _n) : n(_n), seg(4*n){};

    int update(int idx, int p, int l, int r){
        if (r < idx || l > idx) return seg[p];
        if (l == r) return seg[p] = seg[p] + 1;

        int mid = (l+r)/2;
        return seg[p] = update(idx, 2*p, l, mid) + update(idx, 2*p+1, mid+1, r);
    }

    int query(int a, int b, int p, int l, int r){
        if (l > b || r < a) return 0;
        if (l >= a && b >= r){
            return seg[p];
        }

        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);

    for (int i = 0; i < n; i++){
        cout << seg.query(arr[i]-1, n-1, 1, 0, n-1) << " ";
        seg.update(arr[i]-1, 1, 0, n-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}