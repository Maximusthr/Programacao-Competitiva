#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 200;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

bool ok = false;
void dfs (int u, int w){
    vis[u] = true;

    if (u == w){
        ok = true;
        return;
    }

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v, w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    //vector<pair<string, string>> lista;
    map<string, int> paises;
    int id = 1;

    for (int i = 0; i < n; i++){
        string a, b, trash;
        cin >> a >> trash >> trash >> trash >> b;
        //lista.push_back({a, b});

        if (paises[a] == 0){
            paises[a] = id;
            id++;
        }
        if (paises[b] == 0){
            paises[b] = id;
            id++;
        }

        g[paises[a]].push_back(paises[b]);
    }   

    for (int i = 0; i < m; i++){
        string a, b, trash;
        cin >> a >> trash >> trash >> trash >> b;

        if (paises[a] == 0 || paises[b] == 0){
            cout << "Pants on Fire" << "\n";
        }
        else {
            // dfs no pais para tentar achar o outro pais
            dfs(paises[a], paises[b]);
            vis.assign(MAX, false);
            if (ok) cout << "Fact" << "\n";
            else {
                dfs(paises[b], paises[a]);
                if (ok) cout << "Alternative Fact" << "\n";
                else cout << "Pants on Fire" << "\n";
            }
            ok = false;
            vis.assign(MAX, false);
        }
    }
}
