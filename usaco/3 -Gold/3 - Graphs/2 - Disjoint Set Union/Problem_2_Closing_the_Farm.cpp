#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p;
    vector<int> sz;

    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]) {
            p[a] = get(p[a]);
        }
        return p[a];
    }

    bool merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return false;

        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];

        return true;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> path(n);
    for (int i = 0; i < n; i++){
        cin >> path[i];
        path[i]--;
    }
    reverse(path.begin(), path.end());
    
    DSU dsu(n);
    
    vector<bool> cam(n);
    vector<string> ans;
    ans.push_back("YES");

    cam[path[0]] = true;
    int comp = 1;

    for (int i = 1; i < n; i++){
        cam[path[i]] = true;
        comp++;

        for (auto u : g[path[i]]){
            if (cam[u]){
                if (dsu.merge(path[i], u)) comp--;
            }
        }
        
        if (comp == 1) ans.push_back("YES");
        else ans.push_back("NO");
    }

    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    solve();
}