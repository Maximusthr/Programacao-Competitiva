#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<vector<int>> comp, cond;
vector<bool> vis;
vector<int> topo, order;

void dfs(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g[u]) if (!vis[v]) dfs(v);
    topo.push_back(u);
}

void dfs2(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g_rev[u]) if (!vis[v]) dfs2(v);
    order.push_back(u);
}

void solve(){
    int n; cin >> n;

    map<string, int> name;
    vector<pair<int, int>> arr;
    
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        string trash; cin >> trash >> trash;
        string s2; cin >> s2;

        string nam = s.substr(0, (int)s.size()-1);
        
        if (name.find(nam) == name.end()){
            name[nam] = (int) name.size();
        }
        if (name.find(s2) == name.end()){
            name[s2] = (int) name.size();
        }
        
        arr.push_back({name[s2], name[nam]});
    }

    g.resize(name.size()), vis.resize(name.size()), g_rev.resize(name.size());

    for (int i = 0; i < arr.size(); i++){
        g[arr[i].first].push_back(arr[i].second);
        g_rev[arr[i].second].push_back(arr[i].first);
    }

    for (int i = 0; i < name.size(); i++){
        if (!vis[i]) dfs(i);
    }

    reverse(topo.begin(), topo.end());
    vis.assign(n, false);

    vector<int> roots(name.size());
    vector<bool> usou(name.size());
    
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            comp.push_back(order);
            int x = order[0];
            usou[x] = true;
            for (auto v : order){
                roots[v] = x;
            }
            order.clear();
        }
    }

    vector<int> degree(name.size());
    cond.resize(name.size());

    for (int i = 0; i < g.size(); i++){
        for (auto v : g[i]){
            if (roots[i] != roots[v]){
                cond[roots[i]].push_back(roots[v]);
                degree[roots[v]]++;
            }
        }
    }

    int zero = 0;
    for (int i = 0; i < name.size(); i++){
        if (usou[i]){
            if (!degree[i]) zero++;
        }
    }

    if (comp.size() == 1 || zero == 1){
        cout << "possible" << "\n";
        return;
    }   
    
    cout << "impossible" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}