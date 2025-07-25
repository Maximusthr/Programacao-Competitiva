#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<int>> g;
vector<vector<bool>> vis;

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, -1, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && g[x][y] == 1);
}

pair<int, int> bfs(int u, int v){
    if (!vis[u][v]){
        vis[u][v] = true;
    }

    queue<pair<int, int>> fila;

    fila.push({u, v});

    pair<int, int> w;
    while(!fila.empty()){
        w = fila.front();
        vis[w.first][w.second] = true;

        fila.pop();

        for (int i = 0; i < 4; i++){
            int cx = w.first + pos_X[i];
            int cy = w.second + pos_Y[i];

            if (isValid(cx, cy)){
                fila.push({cx, cy});
                vis[cx][cy] = true;
            }
        }
    }

    return w;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    int x, y; cin >> x >> y;
    
    g.resize(n, vector<int> (m));
    vis.resize(n, vector<bool> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    x--, y--;

    pair<int, int> ans;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == x && j == y){
                ans = bfs(i, j);
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1<< "\n";
}
