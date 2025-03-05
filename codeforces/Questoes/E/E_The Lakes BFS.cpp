#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX = 1e3+1;
int g[MAX][MAX];
bool vis[MAX][MAX];
// vector<vector<int>> g(MAX, vector<int>(MAX));
// vector<vector<bool>> vis(MAX, vector<bool>(MAX));
// vector<vector<int>> path(MAX);
 
int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, -1, 1, 0};

bool isValid(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

int bfs(int u, int v){
    queue<pair<int, int>> fila;
    fila.push({u, v});
    int sum = 0;
    
    while (!fila.empty()){
        auto [cx, cy] = fila.front();
        vis[cx][cy] = true;
        sum += g[cx][cy];
        fila.pop();

        for (int i = 0; i < 4; i++){
            int valor_x = cx + pos_X[i];
            int valor_y = cy + pos_Y[i];
            if (!isValid(valor_x, valor_y)) continue;
    
            if (g[valor_x][valor_y] != 0 && !vis[valor_x][valor_y]){
                vis[valor_x][valor_y] = true;
                fila.push({valor_x, valor_y});
            }
        }
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        // g.assign(MAX, vector<int>(MAX));
        // vis.assign(MAX, vector<bool>(MAX));

        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> g[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (g[i][j] > 0 && !vis[i][j]){
                    ans = max(ans, bfs(i, j));
                }
            }
        }

        cout << ans << "\n";
    }
}
