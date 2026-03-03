#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

int n, m;
vector<vector<int>> g;
vector<bool> vis;

vector<int> color;
bool isBirpatite(int u, int c){
    if (color[u] == -1) color[u] = c;

    for (auto v : g[u]){
        if (color[v] == -1){
            if (!isBirpatite(v, c^1)) return false;
        }
        else {
            if (color[v] == color[u]) return false;
        }
    }

    return true;
};

ll bfs(int u, bool call){
    queue<pair<int, int>> q;
    q.push({u, 1});

    // call == false -> 0 é 2
    // call == true -> 0 = [1, 3];
    
    ll ans = 0;
    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        vis[u] = true;
        
        if (call){
            if (v & 1) ans++;
        }
        else {
            if (v % 2 == 0) ans++;
        }

        for (auto w : g[u]){
            if (!vis[w]){
                vis[w] = true;
                q.push({w, v+1});
            }
        }
    }
    return ans;
}

ll Mul(ll a, int tipo){
    ll ans = 1;
    for (int i = 0; i < a; i++){
        ans = (ans * tipo) % MOD;
    }
    return ans % MOD;
};


void solve(){
    vis.clear();
    g.clear();
    color.clear();

    cin >> n >> m;

    g.resize(n);
    vis.resize(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }   

    int comp = 0;

    // eu preciso contar os ciclos
    // e se: (v & 1) -> (ciclo impar: ans = 0)
    // basta ver se é bipartido
    color.resize(n, -1);
    for (int i = 0; i < n; i++){
        if (color[i] == -1){
            if (!isBirpatite(i, 0)){
                cout << 0 << "\n";
                return;
            }
            comp++;
        }
    }

    vector<pair<int, int>> todos(comp);

    vis.assign(n, false);
    int idx = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            int v = bfs(i, 0);
            todos[idx].first = v;
            idx++;
        }
    }

    idx = 0;
    vis.assign(n, false);
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            int v = bfs(i, 1);
            todos[idx].second = v;
            idx++;
        }
    }

    ll resp = 1;
    for (int i = 0; i < comp; i++){
        ll prob = (Mul(todos[i].first, 2) + Mul(todos[i].second, 2)) % MOD;
        resp = (resp % MOD * prob % MOD) % MOD;
    }

    cout << resp % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}