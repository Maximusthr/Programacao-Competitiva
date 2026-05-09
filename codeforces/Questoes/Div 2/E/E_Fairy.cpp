#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+5;

vector<vector<pair<int, int>>> g(MAX);
vector<int> dp_b(MAX), dp_r(MAX), color(MAX, -1), vis(MAX);
vector<int> depth(MAX);
vector<bool> span_ed(MAX);

int t_ruins = 0;
int back_edge = -1;

void dfs(int u, int p, int c){
    if (color[u] == -1) {
        color[u] = c;
        vis[u] = 1;
    }

    for (auto [v, idx] : g[u]){
        if (v == p) continue;

        if (color[v] != -1 && vis[v] == 1){
            // back edge
            if (color[v] == color[u]) {
                dp_r[u]++;
                dp_r[v]--;
                t_ruins++;
                back_edge = idx;
            }
            else {
                dp_b[u]++;
                dp_b[v]--;
            }
        }
        else if (vis[v] == 0 && color[v] == -1){
            // span-edge
            depth[v] = depth[u] + 1;
            span_ed[idx] = true;
            dfs(v, u, c ^ 1);

            dp_b[u] += dp_b[v];
            dp_r[u] += dp_r[v];
        }
    }
    vis[u] = 2;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
        edges[i] = {x, y};
    }

    int comp = 0;
    for (int i = 0; i < n; i++){
        if (color[i] == -1){
            dfs(i, -1, 0);
            comp++;
        }
    }

    if (t_ruins == 0){
        cout << m << "\n";
        for (int i = 1; i <= m; i++){
            cout << i << " \n"[i == n];
        }
        return;
    }
    
    vector<int> ans;

    if (t_ruins == 1 && back_edge != -1){
        ans.push_back(back_edge + 1);
    }
    
    for (int i = 0; i < m; i++){
        if (!span_ed[i]) continue;

        int x = edges[i].first;
        int y = edges[i].second;
        
        if (depth[x] > depth[y]) swap(x, y);

        if (dp_r[y] == t_ruins && dp_b[y] == 0){
            ans.push_back(i+1);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}