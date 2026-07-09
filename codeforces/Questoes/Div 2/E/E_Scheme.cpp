#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<vector<int>> cond;
vector<bool> vis;
vector<int> topo, order;

void dfs1(int u){
    vis[u] = true;
    for (auto v : g[u]){
        if (!vis[v]) dfs1(v);
    }
    topo.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    for (auto v : g_rev[u]){
        if (!vis[v]) dfs2(v);
    }
    order.push_back(u);
}

map<int, int> mapa;
vector<int> only_out, only_in;
vector<bool> pode2;

int node = -1;
void dfs3(int u){
    vis[u] = true;

    for (auto v : cond[u]){
        if (!vis[v]) {
            dfs3(v);
            if (cond[v].size() == 0){
                mapa[u] = v;
                node = v;
            }
            else if (mapa.count(v) && pode2[mapa[v]]) mapa[u] = mapa[v];
        }
    }
}

void solve(){
    int n; cin >> n;

    g.resize(n), g_rev.resize(n);
    vis.resize(n);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        g[i].push_back(x);
        g_rev[x].push_back(i);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs1(i);
    }

    vis.assign(n, false);
    reverse(topo.begin(), topo.end());

    vector<int> roots(n);
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);

            int x = order[0];
            for (auto v : order){
                roots[v] = x;
            }
            order.clear();
        }
    }

    vector<bool> pode(n);
    for (int i = 0; i < n; i++){
        pode[roots[i]] = 1;
    }

    cond.resize(n);
    vector<int> out(n), in(n);
    for (int i = 0; i < n; i++){
        int x = roots[i];
        for (auto u : g[i]){
            if (x != roots[u]){
                cond[x].push_back(roots[u]);
                out[x]++;
                in[roots[u]]++;
            }
        }
    }

    vector<int> both;
    for (int i = 0; i < n; i++){
        if (pode[roots[i]]){
            pode[roots[i]] = false;
            if (in[roots[i]] == 0 && out[roots[i]] == 0) both.push_back(roots[i]);
            else if (out[roots[i]] == 0) only_in.push_back(roots[i]);
            else if (in[roots[i]] == 0) only_out.push_back(roots[i]);
        }
    }

    if (both.size() == 1 && only_in.size() == 0 && only_out.size() == 0){
        cout << 0 << "\n";
        return;
    }

    // a ideia é:
    // conectar o fim de um componente no inicio do outro
    // assim por diante
    
    vector<pair<int, int>> ans;
    vis.assign(n, false);
    pode2.assign(n, true);
    for (int i = 0; i < only_out.size(); i++){
        if (!vis[roots[only_out[i]]]) {
            dfs3(roots[only_out[i]]);
            pode2[node] = false;
        }
    }

    vector<pair<int, int>> pares;
    vector<int> nobody;
    for (int i = 0; i < only_out.size(); i++){
        if (mapa.count(only_out[i])){
            pares.push_back({only_out[i], mapa[only_out[i]]});
        }
        else nobody.push_back(only_out[i]);
    }

    for (int i = 0; i < (int)pares.size() - 1; i++){
        ans.push_back({pares[i].second, pares[i+1].first});
    }
    int last = -1;

    // preciso conectar pares[0].first
    if (pares.size() > 0){
        last = pares.back().second;
    }
    if (last == -1){
        if (both.size() > 1){
            for (int i = 0; i < both.size()-1; i++){
                ans.push_back({both[i], both[i+1]});
            }
            ans.push_back({both.back(), both[0]});
        }
    }
    else {
        for (int i = 0; i < both.size(); i++){
            ans.push_back({last, both[i]});
            last = both[i];
        }
        for (int i = 0; i < nobody.size(); i++){
            ans.push_back({last, nobody[i]});
            last = nobody[i];
        }
        ans.push_back({last, pares[0].first});
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}