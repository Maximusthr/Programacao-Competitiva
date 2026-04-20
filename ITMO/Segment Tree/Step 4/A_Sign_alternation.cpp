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
        return seg[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    int update(int idx, int v, int p, int l, int r){
        if (l > idx || idx > r) return seg[p];
        if (l == r) return seg[p] = v;

        int mid = (l+r)/2;
        return seg[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }

    int query(int a, int b, int p, int l, int r){
        if (l > b || a > r) return 0;
        if (l >= a && b >= r) return seg[p];
        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i & 1) arr[i] *= -1;
    }

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if (x == 0){
            int i, j; cin >> i >> j;    
            i--;
            if (arr[i] < 0) j *= -1;
            seg.update(i, j, 1, 0, n-1);
        }
        else {
            int a, b; cin >> a >> b;
            a--, b--;
            int ans = seg.query(a, b, 1, 0, n-1);   

            if (arr[a] < 0) ans *= -1;
            
            cout << ans << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}