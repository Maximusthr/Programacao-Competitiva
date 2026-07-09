#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int _n) : n(_n), bit(n+1) {};

    BIT(vector<int> &id, vector<ll> &sum) : n (id.size()), bit(n+1){
        for (int i = 1; i <= n; i++){
            bit[i] += sum[id[i-1]];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    };

    void update(int i, ll valor){
        for (i++; i <= n; i += i & -i){
            bit[i] += valor;
        }
    }

    ll sum(int i){
        ll resp = 0;
        for (i++; i; i -= i & -i){
            resp += bit[i];
        }
        return resp;
    }

    ll query(ll a, ll b){
        return sum(b) - sum(a-1);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> val(n);
    for (auto &i : val) cin >> i;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    map<int, int> mapa;
    vector<int> id;
    vector<int> sub_tree(n);
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;
        id.push_back(u);
        mapa[u] = id.size()-1;
        sub_tree[u] = 1;
        for (auto v : g[u]){
            if (!vis[v]) {
                self(self, v);
                sub_tree[u] += sub_tree[v];
            }
        }
    };

    dfs(dfs, 0);

    BIT bit(id, val);
    while(q--){
        int x; cin >> x;
        if (x == 2){
            int y; cin >> y;
            y--;
            ll ans = bit.query(mapa[y], mapa[y] + sub_tree[y] - 1);
            cout << ans << "\n";
        }
        else {
            int y, z; cin >> y >> z;
            y--;
            bit.update(mapa[y], z - val[y]);;
            val[y] = z;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}