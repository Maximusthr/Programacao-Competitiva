#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {}

    int build(string s, int p, int l, int r){
        if (l == r) return seg[p] = (1 << (s[l]-'a'));

        int mid = (l+r)/2;
        return seg[p] = (build(s, 2*p, l, mid) | build(s, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && r <= b) return seg[p];

        int mid = (l+r)/2;
        return (query(a, b, 2*p, l, mid) | query(a, b, 2*p+1, mid+1, r));
    }

    int update(int idx, char v, int p, int l, int r){
        if (idx < l || idx > r) return seg[p];
        if (l == r) return seg[p] = (1 << (v-'a'));

        int mid = (l+r)/2;
        return seg[p] = (update(idx, v, 2*p, l, mid) | update(idx, v, 2*p+1, mid+1, r));
    }
};

void solve(){
    string s; cin >> s;
    
    int n = (int)s.size();

    int q; cin >> q;

    Seg seg(n);
    seg.build(s, 1, 0, n-1);

    while(q--){
        int x; cin >> x;
        if (x == 1){
            int idx; char v; cin >> idx >> v;
            idx--;

            seg.update(idx, v, 1, 0, n-1);
        }
        else {
            int a, b; cin >> a >> b;
            a--, b--;

            cout << __builtin_popcount(seg.query(a, b, 1, 0, n-1)) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}