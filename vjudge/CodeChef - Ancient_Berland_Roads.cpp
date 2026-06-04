#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<ll> p, sz, popu;

    DSU (int n) : p(n), sz(n, 1), popu(n){
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
        p[a] = b;
        sz[b] += sz[a];
        popu[b] += popu[a];
    }
};

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<ll> v(n);

    vector<vector<int>> index(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v[i] = x;
        index[i].push_back(x);
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        edges[i] = {x, y};
    }

    struct Q {
        char tipo;
        int x, y;
    };

    vector<Q> queries;
    vector<bool> exist(m);
    for (int i = 0; i < q; i++){
        char c; cin >> c;
        if (c == 'P'){
            int idx, val; cin >> idx >> val;
            idx--;
            v[idx] = val;
            index[idx].push_back(val);
            queries.push_back({c, idx, val});
        }
        else {
            int idx; cin >> idx;
            idx--;
            queries.push_back({c, idx, -1});
            exist[idx] = true;
        }
    }

    DSU dsu(n);
    for (int i = 0; i < n; i++){
        dsu.popu[i] = v[i];
    }
    for (int i = 0; i < m; i++){
        if (!exist[i]){
            auto [x, y] = edges[i];
            dsu.merge(dsu.get(x), dsu.get(y));
        }
    }
    
    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++){
        pq.push({dsu.popu[dsu.get(i)], i});
    }

    vector<ll> ans;
    for (int i = q-1; i >= 0; i--){
        while (!pq.empty() && dsu.popu[dsu.get(pq.top().second)] != pq.top().first) {
            pq.pop();
        }
        auto topo = pq.top();

        if (queries[i].tipo == 'D'){
            ans.push_back(topo.first);

            dsu.merge(dsu.get(edges[queries[i].x].first), dsu.get(edges[queries[i].x].second));

            pq.push({dsu.popu[dsu.get(edges[queries[i].x].first)], edges[queries[i].x].first});
            pq.push({dsu.popu[dsu.get(edges[queries[i].x].second)], edges[queries[i].x].second});
        }
        else {
            ans.push_back(topo.first);

            int idx = queries[i].x;
            ll old = queries[i].y;

            index[idx].pop_back();

            ll atual = index[idx].back();
            v[idx] = atual;

            dsu.popu[dsu.get(idx)] += atual - old;

            pq.push({dsu.popu[dsu.get(idx)], idx});
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}