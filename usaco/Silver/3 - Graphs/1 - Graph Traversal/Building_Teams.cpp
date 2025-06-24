#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;

vector<int> g[MAX];
vector<int> c(MAX, -1);

bool ok = true;

void dfs(int u, int color){
    if (c[u] == -1) {
        c[u] = color;
    }

    for (auto v : g[u]){
        if (c[v] == color){
            ok = false;
            return;
        }
        else if (c[v] == -1){
            dfs(v, color ^ 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (c[i] == -1){
            dfs(i, 0);
            if (!ok){
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << c[i] + 1 << " ";
    }
    cout << "\n";
}