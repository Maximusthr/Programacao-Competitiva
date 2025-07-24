#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<string> g;
vector<vector<bool>> vis;

int X[] = {-1, 0, 0, 1};
int Y[] = {0, 1, -1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && g[x][y] != '#');
}

bool fim = false;

void bfs_B(int u, int v){
    queue<pair<int, int>> q;
    q.push({u, v});
    while(!q.empty()){
        pair<int, int> c = q.front();
        if (!vis[c.first][c.second]){
            vis[c.first][c.second] = true;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int cx = c.first + X[i];
            int cy = c.second + Y[i];
            if (isValid(cx, cy)){
                if (g[cx][cy] == 'G'){
                    fim = true;
                    return;
                }
                else if (g[cx][cy] == '.'){
                    g[cx][cy] = '#';
                }
                else if (g[cx][cy] == 'B'){
                    q.push({cx, cy});
                    vis[cx][cy] = true;
                }
            }
        }
    }
}

void bfs_fim(int u, int v){
    queue<pair<int, int>> q;
    q.push({u, v});
    while(!q.empty()){
        pair<int, int> c = q.front();
        if (!vis[c.first][c.second]){
            vis[c.first][c.second] = true;
        }
        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = c.first + X[i];
            int cy = c.second + Y[i];
            if (isValid(cx, cy)){
                q.push({cx, cy});
                vis[cx][cy] = true;
            }
        }
    }   
}

void solve(){
    cin >> n >> m;
    g.resize(n);
    vis.resize(n, vector<bool> (m));
    
    bool G = false, B = false;
    for (int i = 0; i < n; i++){
        cin >> g[i];
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'G'){
                G = 1;
            }
            if (g[i][j] == 'B'){
                B = 1;
            }
        }
    }

    if (!G) {
        cout << "YES" << "\n";
        return;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && g[i][j] == 'B'){
                bfs_B(i, j);
            }
        }
    }

    if (fim || (g[n-1][m-1] == '#')){
        cout << "NO" << "\n";
        return;
    }

    // Rodo um bfs do (m-1 e n-1) e vejo se todos os G foram visitados
    vis.assign(n, vector<bool> (m));
    bfs_fim(n-1, m-1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if ((g[i][j] == 'G' && !vis[i][j])){
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << "YES" << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        g.clear();
        vis.clear();
        fim = false;
        solve();
    }
}