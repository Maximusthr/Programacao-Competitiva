#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 205;
int n;

vector<vector<int>> g(MAX);
vector<int> vis(MAX);

struct cows{
    int x, y, p;
};
int dist(cows a, cows b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

vector<cows> c(n);
int aux = 1;
void dfs(int u){
    if (!vis[u]) vis[u] = true;

    for (auto v : g[u]){
        if (!vis[v]){
            if (c[u].p*c[u].p >= dist(c[u], c[v])){
                aux++;
                dfs(v);
            }
        }
    }
}

void solve(){
    cin >> n;

    c.resize(n);

    for (int i = 0; i < n; i++){
        int x, y, p; cin >> x >> y >> p;
        c[i] = {x, y, p};
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            g[i].push_back(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        dfs(i);
        ans = max(ans, aux);
        aux = 1;
        vis.assign(MAX, false);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    solve();
}