#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
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
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, q; cin >> n >> m >> q;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    DSU dsu(n);

    struct queries {
        string x;
        int y, z;
    };

    vector<string> ans;
    vector<queries> query;
    for (int i = 0; i < q; i++){
        string s;
        int a, b;
        cin >> s >> a >> b;
        a--, b--;
        query.push_back({s, a, b});
    }

    reverse(query.begin(), query.end());

    for (int i = 0; i < q; i++){
        if (query[i].x == "ask"){
            int a = query[i].y;
            int b = query[i].z;

            if (dsu.get(a) == dsu.get(b)) ans.push_back("YES");
            else ans.push_back("NO");
        }
        else {
            int a = query[i].y;
            int b = query[i].z;

            dsu.merge(a, b);
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto c : ans) cout << c << "\n";
}