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

int dfs(int u, int v){
    vis[u][v] = true;

    int sum = g[u][v];

    for (int i = 0; i < 4; i++){
        int cx = u + pos_X[i];
        int cy = v + pos_Y[i];
        if (!isValid(cx, cy)) continue;

        if (g[cx][cy] != 0 && !vis[cx][cy]){
            sum += dfs(cx, cy);
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
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        // int ans = 0;
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++){
        //         ans = max(ans, path[i][j]);
        //     }
        // }

        cout << ans << "\n";
    }
}
