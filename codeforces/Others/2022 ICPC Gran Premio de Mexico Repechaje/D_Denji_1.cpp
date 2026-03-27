/**
* @file D_Denji_1.cpp
* @author GabrielCampelo
* Created on 2026-03-27 at 09:10:02
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    ll val;
    node() {
        val = 0;
    }
    node(ll val) : val(val) {
    }
    node operator + (const node &rhs) const {
        return node(val + rhs.val);
        // return node(val op rhs.val);
    }
};

struct SegTree {
    int n;
    vector<node> t;

    SegTree(int n) : n(n) {
        t.assign(4 * n, node());
    }

    SegTree(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int pos, int l, int r, vector<int> &a) {
        if(l == r) {
            t[pos] = node(a[l]);
            return; 
        }
        int m = (l + r) / 2;
        build(2 * pos, l, m, a);
        build(2 * pos + 1, m + 1, r, a);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    void update(int i, int val, int pos, int l, int r) {
        if(l == r) {
            t[pos] = node(val);
            return;
        }
        int m = (l + r) / 2;
        if(i <= m) update(i, val, 2 * pos, l, m);
        else update(i, val, 2 * pos + 1, m + 1, r);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
    void update(int i, int val) { 
        update(i, val, 1, 0, n - 1);
    }

    node query(int i, int j, int pos, int l, int r) {
        if(j < l || r < i) return node();
        if(i <= l && r <= j) return t[pos];
        int m = (l + r) / 2;
        return query(i, j, 2 * pos, l, m) + query(i, j, 2 * pos + 1, m + 1, r);
    }
    node query(int i, int j) {
        return query(i, j, 1, 0, n - 1);
    }
};

template <typename T>
struct CoordinateCompression {
    vector<T> d;

    CoordinateCompression(const vector<T> &vec) {
        d = vec;
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
    }

    int get_id(T x) {
        return lower_bound(d.begin(), d.end(), x) - d.begin();
    }

    T get_value(int id) {
        return d[id];
    }
};

int main() { _
    int m;
    cin >> m;

    vector<ll> num(m + 1);
    vector<vector<int>> queries(m + 1, vector<int>(3));
    vector<ll> coords;

    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int a;
            cin >> a;

            num[i] = a;

            coords.pb(num[i]);
            queries[i] = {type, a, 0};
        } else if (type == 2) {
            int b;
            cin >> b;

            queries[i] = {type, b, 0};
        } else if (type == 3) {
            int b, a;
            cin >> b >> a;

            num[b] += a;
            num[i] = num[b];

            coords.pb(num[i]);
            queries[i] = {type, b, a};
        } else {
            int b;
            cin >> b;
            
            queries[i] = {type, b, 0};
        }
    }

    CoordinateCompression cc(coords);
    SegTree seg(coords.size());

    for (int i = 1; i <= m; i++) {
        int type = queries[i][0];

        if (type == 1) {
            int a = queries[i][1];
            num[i] = a;
            int id = cc.get_id(num[i]);
            seg.update(id, seg.query(id, id).val + 1);
        } else if (type == 2) {
            int b = queries[i][1];
            int id = cc.get_id(num[b]);
            seg.update(id, seg.query(id, id).val - 1);
        } else if (type == 3) {
            int b = queries[i][1], a = queries[i][2];
            int id = cc.get_id(num[b]);
            seg.update(id, seg.query(id, id).val - 1);
            num[b] += a;
            num[i] = num[b];
            id = cc.get_id(num[i]);
            seg.update(id, seg.query(id, id).val + 1);
        } else {
            int b = queries[i][1];
            int id = cc.get_id(num[b]);
            cout << seg.query(0, id - 1).val << endl;
        }
    }

    return 0;
}