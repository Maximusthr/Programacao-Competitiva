#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5;
vector<int> g[MAX];
vector<int> c(MAX, -1);

bool bipartido = true;
void dfs(int u, int color){
    if (c[u] == -1){
        c[u] = color;
    }

    for (auto w : g[u]){
        if (c[w] == -1){
            dfs(w, color ^ 1);
        }
        else if (c[w] == color){
            bipartido = false;
            return;
        }
    }
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

    for (int i = 0; i < n; i++){
        if (c[i] == -1){
            dfs(i, 0);
        }
    }

    if (!bipartido) cout << "IMPOSSIBLE" << "\n";
    else {
        for (int i = 0; i < n; i++){
            if (c[i] == 0) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
    }
}