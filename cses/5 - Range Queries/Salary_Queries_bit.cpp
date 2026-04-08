#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int _n) : n(_n), bit(n+1) {}

    BIT(vector<int> &v) : n(v.size()), bit(n+1) {
        for (int i = 1; i <= n; i++){
            bit[i] += v[i-1];
            int j = i + i & -i;
            if (j <= n) bit[j] += bit[i];
        }
    };

    int sum (int i){
        int ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }
    int query(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int i, int v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
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

    auto index = [&](int x){
        return lower_bound(compress.begin(), compress.end(), x) - compress.begin();
    };

    BIT bit((int)compress.size());
    for (int i = 0; i < n; i++){
        bit.update(index(p[i]), 1);
    }

    for (int i = 0; i < q; i++){
        if (c[i] == '?'){
            cout << bit.query(index(a[i]), index(b[i])) << "\n";
        }
        else {
            bit.update(index(p[a[i]]), -1);
            p[a[i]] = b[i];
            bit.update(index(p[a[i]]), 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}