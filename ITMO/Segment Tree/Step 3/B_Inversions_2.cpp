#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg(int n) : seg(4*n){};

    int build(int p, int l, int r){
        if (l == r) return seg[p] = 1;

        int mid = (l+r)/2;
        return seg[p] = build(2*p, l, mid) + build(2*p+1, mid+1, r);
    }

    int update(int idx, int p, int l, int r){
        if (l > idx || r < idx) return seg[p];
        if (l == r){
            seg[p] = 0;
            return seg[p];
        }

        int mid = (l+r)/2;
        return seg[p] = update(idx, 2*p, l, mid) + update(idx, 2*p+1, mid+1, r);
    }

    int query(int sum, int p, int l, int r){
        if (l == r) return l;

        int mid = (l+r)/2;

        if (seg[2*p] >= sum) return query(sum, 2*p, l, mid);
        else return query(sum - seg[2*p], 2*p+1, mid+1, r);
    }
};

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(1, 0, n-1);

    vector<int> ans;

    for (int i = n-1; i >= 0; i--){
        int k = (i + 1) - arr[i];

        int v = seg.query(k, 1, 0, n-1);
        ans.push_back(v);
        seg.update(v, 1, 0, n-1);
    }
    reverse(ans.begin(), ans.end());
    for (auto &i : ans) cout << i+1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}