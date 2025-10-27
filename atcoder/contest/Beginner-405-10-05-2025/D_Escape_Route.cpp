#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<string> g;
vector<vector<int>> dist;

int pos_X[] = {0, -1, 1, 0};
int pos_Y[] = {1, 0, 0, -1};

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m && g[x][y] != '#');
}

void bfs_ms(vector<pair<int, int>> &E){
    queue<pair<int, int>> q;

    for (int i = 0; i < E.size(); i++){
        q.push({E[i].first, E[i].second});
        dist[E[i].first][E[i].second] = 0;
    }

    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int cx = u + pos_X[i];
            int cy = v + pos_Y[i];

            if (isValid(cx, cy)){
                if (dist[u][v] + 1 < dist[cx][cy]){
                    dist[cx][cy] = dist[u][v] + 1;
                    q.push({cx, cy});
                }
            }
        }
    }
}

void bfs(vector<pair<int, int>> &E){
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool> (m));

    for (int i = 0; i < E.size(); i++){
        q.push({E[i].first, E[i].second});
        vis[E[i].first][E[i].second] = true;
    }

    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = u + pos_X[i];
            int cy = v + pos_Y[i];

            if (isValid(cx, cy) && !vis[cx][cy]){
                if (dist[cx][cy] > dist[u][v]){
                    if (pos_X[i] == 0 && pos_Y[i] == 1){
                        g[cx][cy] = '<';
                    }
                    else if (pos_X[i] == 0 && pos_Y[i] == -1){
                        g[cx][cy] = '>';
                    }
                    else if (pos_X[i] == 1 && pos_Y[i] == 0){
                        g[cx][cy] = '^';
                    }
                    else if (pos_X[i] == -1 && pos_Y[i] == 0){
                        g[cx][cy] = 'v';
                    }
                    q.push({cx, cy});
                    vis[cx][cy] = true;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, vector<int> (m, INF));

    vector<pair<int, int>> emerg;

    for (int i = 0; i < n; i++){
        cin >> g[i];
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'E') emerg.push_back({i, j});
        }
    }

    bfs_ms(emerg);
    bfs(emerg);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << g[i][j];
            if (j == m-1) cout << "\n";
        }
    }
}