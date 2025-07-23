#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
// const int MAX = 51;
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

bool bfs_G(int u, int v){
    queue<pair<int, int>> q;
    q.push({u, v});
    while(!q.empty()){
        pair<int, int> c = q.front();
        if (!vis[c.first][c.second]){
            vis[c.first][c.second] = true;
        }
        q.pop();
        
        if (c.first == n-1 && c.second == m-1){
            return true;
        }

        for (int i = 0; i < 4; i++){
            int cx = c.first + X[i];
            int cy = c.second + Y[i];
            if (isValid(cx, cy)){
                q.push({cx, cy});
                vis[cx][cy] = true;
            }
        }
    }   
    return false;
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

    if (!G || !B) {
        cout << "YES" << "\n";
        return;
    }

    // rodar BFS
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && g[i][j] == 'B'){
                bfs_B(i, j);
            }
        }
    }

    if (fim){
        cout << "NO" << "\n";
        return;
    }

    // tampei tudo, verifico se G consegue chegar
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && g[i][j] == 'G'){
                if (!bfs_G(i, j)){
                    cout << "NO" << "\n";
                    return;
                }
            }
            // vis.assign(false, vector<bool> (false));
            vis.assign(n, vector<bool> (m));
        }
    }

    cout << "YES" << "\n";
    return;
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