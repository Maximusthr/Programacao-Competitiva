#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Coord{
    int x, y;
};

const int MAX = 1e5+1;

vector<int> g[MAX];
vector<int> vis(MAX);
vector<vector<int>> comp;

void dfs(int u, int i){
    if (!vis[u]) vis[u] = true;

    comp[i].push_back(u);

    for (auto v : g[u]){
        if (!vis[v]) {
            dfs(v, i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<Coord> pos;

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        pos.push_back({x, y});
    }

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    comp.resize(n);
    for (int i = 0, j = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, j);
            j++;
        }
    }

    ll ans = LINF;
    for (int i = 0; i < comp.size(); i++){
        ll min_x = LINF, min_y = LINF, max_x = 0, max_y = 0;
        for (int j = 0; j < comp[i].size(); j++){
            min_x = min(min_x, 1LL*pos[comp[i][j]].x);
            min_y = min(min_y, 1LL*pos[comp[i][j]].y);

            max_x = max(max_x, 1LL*pos[comp[i][j]].x);
            max_y = max(max_y, 1LL*pos[comp[i][j]].y);
        }
        ans = min(ans, ((max_x - min_x) * 2) + ((max_y - min_y) * 2));
    }

    cout << ans << "\n";
}