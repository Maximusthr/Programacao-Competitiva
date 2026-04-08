#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg{
    vector<int> seg;

    Seg (int n) : seg(4*n) {};

    int update(int idx, int v, int p, int l, int r){
        if (r < idx || l > idx) return seg[p];
        if (l == r){
            return seg[p] = seg[p] + v;
        }

        int mid = (l+r)/2;
        return seg[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }

    int query(int a, int b, int p, int l, int r){
        if (r < a || l > b) return 0;
        if (l >= a && r <= b){
            return seg[p];
        }

        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    
    vector<int> p(n);
    vector<int> compress;
    for (int i = 0; i < n; i++){
        cin >> p[i];
        compress.push_back(p[i]);
    }
    
    vector<char> c(q);
    vector<int> a(q), b(q);

    for (int i = 0; i < q; i++){
        cin >> c[i] >> a[i] >> b[i];
        if (c[i] == '?'){
            compress.push_back(a[i]);
            compress.push_back(b[i]);
        }
        else {
            a[i]--;
            compress.push_back(b[i]);
        }
    }
    
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

    auto index = [&](int x) -> int {
        return lower_bound(compress.begin(), compress.end(), x) - compress.begin();
    };

    int nn = compress.size();

    Seg seg(nn);

    for (int i = 0; i < n; i++){
        seg.update(index(p[i]), 1, 1, 0, nn-1);
    }

    for (int i = 0; i < q; i++){
        if (c[i] == '?'){
            int aa = index(a[i]);
            int bb = index(b[i]);

            cout << seg.query(aa, bb, 1, 0, nn-1) << "\n";
        }
        else {
            int aa = a[i]; // indice
            seg.update(index(p[aa]), -1, 1, 0, nn-1);
            p[aa] = b[i];
            seg.update(index(p[aa]), 1, 1, 0, nn-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}