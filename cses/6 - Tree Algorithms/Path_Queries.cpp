#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<ll> bit;

    BIT (int _n) : n(_n), bit(n+1){}

    void update(int i, ll v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    ll query(int i){
        ll ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> sz(n);
    vector<ll> path(n);
    vector<int> start(n), end(n);
    int time = 0;

    auto dfs = [&](auto &&self, int u, int p) -> void {
        start[u] = time++;
        sz[u] = 1;
        path[u] += v[u];
        for (auto v : g[u]){
            if (v != p){
                path[v] += path[u];
                self(self, v, u);
                sz[u] += sz[v];
            }
        }
        end[u] = time;
    };

    dfs(dfs, 0, -1);

    vector<ll> ordem(n);
    for (int i = 0; i < n; i++){
        ordem[start[i]] = path[i];
    }

    BIT bit(n);

    // for (int i = 0; i < n; i++){
    //     bit.update(i, ordem[i]);
    //     bit.update(i+1, -ordem[i]);
    // }

    for (int i = 0; i < n; i++){
        bit.update(start[i], v[i]);
        bit.update(end[i], -v[i]);
    }

    while(m--){
        int x; cin >> x;
        if (x == 2){
            int y; cin >> y;
            y--;
            cout << bit.query(start[y]) << "\n";
        }
        else {
            int y, z; cin >> y >> z;
            y--;

            bit.update(start[y], z - v[y]);
            bit.update(end[y], -z + v[y]);

            v[y] = z;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}