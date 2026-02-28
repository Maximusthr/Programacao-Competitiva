#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

struct DSU {
    vector<int> p, sz;
    int comp;

    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
        comp = n;
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);

        p[a] = b;
        sz[b] += sz[a];
        comp--;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<int> idx(m);
    idx[0] = 2;
    for (int i = 1; i < m; i++){
        idx[i] = (2 * idx[i-1]) % MOD;
    }

    vector<pair<int, int>> par(m);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        par[i] = {x, y};
    }

    int ans = 0;
    DSU dsu(n);
    for (int i = m-1; i >= 0; i--){
        int x = dsu.get(par[i].first);
        int y = dsu.get(par[i].second);

        if (dsu.comp == 2 && x != y){
            ans = (ans + idx[i]) % MOD;
            continue;
        }

        if (x == y) continue;

        dsu.merge(x, y);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}