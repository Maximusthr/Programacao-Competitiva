#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<ll> bit;

    BIT (int _n) : n(_n), bit(n+1) {};

    void update(int i, ll v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    ll sum(int i){
        ll ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    ll query(int r){
        return sum(r);
    }
};

void solve(){
    int q; cin >> q;

    vector<vector<int>> g;
    vector<array<int, 2>> query;
    int n = 1;
    for (int i = 0; i < q; i++){
        int x; cin >> x;
        if (x == 1){
            int y; cin >> y;
            y--;
            query.push_back({y, INF});
            n++;
        }
        else {
            int y, z; cin >> y >> z;
            y--;
            query.push_back({y, z});
        }
    }

    g.resize(n);
    int dif = 1;
    for (int i = 0; i < q; i++){
        if (query[i][1] != INF) continue;
        int x = query[i][0];
        g[x].push_back(dif);
        g[dif].push_back(x);
        dif++;
    }

    vector<int> start(n), end(n);
    int time = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        start[u] = time++;
        for (auto v : g[u]){
            if (v == p) continue;
            self(self, v, u);
        }
        
        end[u] = time;
    };
    
    dfs(dfs, 0, -1);
    
    BIT bit(n);

    vector<ll> trash(n);
    ll cur = 1;
    for (int i = 0; i < q; i++){
        if (query[i][1] == INF){
            trash[cur] = bit.query(start[cur]);
            cur++;
        }
        else {
            bit.update(start[query[i][0]], query[i][1]);
            bit.update(end[query[i][0]], -query[i][1]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << bit.query(start[i]) - trash[i] << " \n" [i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}