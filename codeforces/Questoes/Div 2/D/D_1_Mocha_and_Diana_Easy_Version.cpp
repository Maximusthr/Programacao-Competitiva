#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
    }
};  

void solve(){
    int n, m1, m2; cin >> n >> m1 >> m2;

    DSU d1(n), d2(n);
    for (int i = 0; i < m1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        d1.merge(x, y);
    }
    for (int i = 0; i < m2; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        d2.merge(x, y);
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int v1 = d1.get(i);
            int v2 = d1.get(j);

            int w1 = d2.get(i);
            int w2 = d2.get(j);

            if (v1 == v2 || w1 == w2) continue;

            ans.push_back({i, j});
            d1.merge(v1, v2);
            d2.merge(w1, w2);
        }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}