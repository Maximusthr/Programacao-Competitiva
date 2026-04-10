#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU{
    vector<int> p, sz;
    set<int> conj;

    DSU (int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; i++){
            p[i] = i;
            conj.insert(i);
        }
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        conj.erase(a);
    }
};

struct Edges {
    int u, v, idx;
};

void solve(){
    int n; cin >> n;

    vector<Edges> g;
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g.push_back({x, y, i});
    }
    
    DSU dsu(n);
    vector<int> ans;
    for (int i = 0; i < n-1; i++){
        int x = dsu.get(g[i].u);
        int y = dsu.get(g[i].v);

        if (x == y){
            ans.push_back(g[i].idx);
            continue;
        }

        dsu.merge(x, y);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << g[ans[i]].u + 1 << " " << g[ans[i]].v + 1 << " ";
        int v = dsu.get(g[ans[i]].u);
        int ini = *dsu.conj.begin();
        int end = *prev(dsu.conj.end());

        if (ini != v){
            cout << v + 1 << " " << ini + 1 << "\n";
            dsu.merge(v, ini);
        }
        else if (v != end){
            cout << v + 1 << " " << end + 1 << "\n";
            dsu.merge(v, end);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}