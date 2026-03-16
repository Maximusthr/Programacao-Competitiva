#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<int> color;

bool bipartite = true;
int sum = 0, sum2 = 0;
void dfs(int u, int c){
    if (color[u] == -1) color[u] = c;

    if (c == 0) sum++;
    else sum2++;

    for (auto v : g[u]){
        if (color[v] == -1){
            dfs(v, c^1);
        }
        else if (color[v] == c){
            bipartite = false;
            // MALDITO RETURN =))))))))))))
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    color.resize(n, -1);
    for (int i = 0; i < n; i++){
        if (color[i] == -1){
            bipartite = true;
            sum = 0, sum2 = 0;
            dfs(i, 0);
            if (bipartite){
                ans += max(sum, sum2);                
            }
        }
    }

    cout << ans << "\n";

    color.clear();
    g.clear();
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}