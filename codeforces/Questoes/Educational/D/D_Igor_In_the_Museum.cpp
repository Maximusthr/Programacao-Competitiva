#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<string> g(n);
    vector<vector<bool>> vis(n, vector<bool> (m));
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {-1, 0, 0, 1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y]);
    };

    vector<vector<int>> qtd(n, vector<int> (m));
    int sum = 0;
    vector<pair<int, int>> coord;

    auto dfs = [&](auto &&self, int u, int v) -> void {
        if (!vis[u][v]) {
            vis[u][v] = true;
            coord.push_back({u, v});
        }

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;
            if (isValid(cx, cy) && g[cx][cy] == '*'){
                sum++;
            }
        }

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;
            if (isValid(cx, cy) && g[cx][cy] != '*'){
                self(self, cx, cy);
            }
        }
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && g[i][j] == '.'){
                dfs(dfs, i, j);
                for (int k = 0; k < coord.size(); k++){
                    auto [x, y] = coord[k];
                    qtd[x][y] = sum;
                }
                sum = 0;
                coord.clear();
            }
        }
    }

    while(q--){
        int x, y; cin >> x >> y;
        x--, y--;

        cout << qtd[x][y] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}