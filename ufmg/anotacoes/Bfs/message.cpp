#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;

vector<int> g[MAX];
vector<bool> vis(MAX);
// para a questao
vector<int> pai(MAX);

void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u] = true;

    pai[u] = u;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for (auto w : g[v]){
            if (!vis[w]){
                q.push(w);
                vis[w] = true;

                pai[w] = v; // aquele respectivo nó está associado a v e v para o outro.. etc
            }
        }
    }
 
}

vector<int> path(int v){
    vector<int> ret;
    if (!vis[v]) return ret;
    ret.push_back(v);
    while(pai[v] != v){
        v = pai[v]; // caminho de pai para pai
        ret.push_back(v);
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(0); // lemos da fonte 0
    vector<int> ans = path(n-1);

    if (ans.size() == 0) cout << "IMPOSSIBLE" << "\n";
    else {
        cout << ans.size() << "\n";
        for (auto u : ans) cout << u+1 << " ";
        cout << "\n";
   }
}
