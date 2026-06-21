#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT (int _n) : n(_n), bit(n+1) {};

    void update(int i, int v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    int query(int i){
        int ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }
};

struct Query{
    char c;
    int l, r;
    int idx;
};

void solve(){
    int n; cin >> n;

    vector<int> compress;
    vector<Query> queries;
    vector<Query> draw;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        if (c == 'D' || c == 'Q'){
            int l, r; cin >> l >> r;
            l--, r--;
            queries.push_back({c, l, r, i});
            compress.push_back(l);
            compress.push_back(r);

            if (c == 'D'){
                draw.push_back({c, l, r, i});
            }
        }
        else {
            int idx; cin >> idx;
            idx--;
            queries.push_back({c, 0, 0, idx});
        }
    }

    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

    auto index = [&](int x) -> int {
        return lower_bound(compress.begin(), compress.end(), x) - compress.begin();
    };

    BIT b_l(compress.size()), b_r(compress.size());
    int total = 0;
    for (int i = 0; i < n; i++){
        char c = queries[i].c;
        int l = queries[i].l;
        int r = queries[i].r;

        if (c == 'D'){
            b_l.update(index(l), 1);
            b_r.update(index(r), 1);
            total++;
        }
        else if (c == 'Q'){
            int dir = total - b_l.query(index(r));
            int esq = b_r.query(index(l)-1);

            cout << total - esq - dir << "\n";
        }
        else {
            int idx = queries[i].idx;

            int l = draw[idx].l;
            int r = draw[idx].r;

            b_l.update(index(l), -1);
            b_r.update(index(r), -1);
            total--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}