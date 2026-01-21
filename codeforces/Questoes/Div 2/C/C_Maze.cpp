#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void solve(){
    cin >> n >> m >> k;

    vector<string> g(n);
    vector<vector<bool>> vis(n, vector<bool> (m));
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && g[x][y] == '.');
    };
    
    auto dfs = [&](auto &&self, int u, int v, vector<pair<int, int>> &c) -> void {
        if (!vis[u][v]) vis[u][v] = true;
        
        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;
            
            if (isValid(cx, cy)){
                self(self, cx, cy, c);
            }
        }
        c.push_back({u, v});
    };

    vector<vector<pair<int, int>>> coord;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (isValid(i, j)){
                vector<pair<int, int>> c;
                dfs(dfs, i, j, c);
                coord.push_back(c);
            }
        }
    }

    sort(coord.begin(), coord.end());

    for (int i = 0; i < coord.size(); i++){
        for (int j = 0; j < coord[i].size(); j++){
            if (k > 0){
                g[coord[i][j].first][coord[i][j].second] = 'X';
                k--;
            }
        }
        if (k == 0) break;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << g[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}