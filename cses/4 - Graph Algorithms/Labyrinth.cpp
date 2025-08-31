#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<string> s;
vector<vector<bool>> vis;
vector<vector<int>> dist;
pair<int, int> start;
pair<int, int> fim;

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, -1, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && s[x][y] != '#');
}

bool ok = false;
void bfs(int x, int y){
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});

    while(!q.empty()){
        auto [v, w] = q.front();
        q.pop();

        if (!vis[v][w]) vis[v][w] = true;

        if (v == fim.first && w == fim.second){
            ok = true;
            return;
        }

        for (int i = 0; i < 4; i++){
            int cx = pos_X[i] + v;
            int cy = pos_Y[i] + w;

            if (isValid(cx, cy)){
                vis[cx][cy] = true;
                dist[cx][cy] = dist[v][w] + 1;
                q.push({cx, cy});
            }
        }

    }
}

string caminho;
void reconstruir(int x, int y){
    queue<pair<int, int>> q;

    q.push({x, y});

    while(!q.empty()){
        auto [v, w] = q.front();
        q.pop();

        if (v == start.first && w == start.second){
            return;
        }

        for (int i = 0; i < 4; i++){
            int cx = pos_X[i] + v;
            int cy = pos_Y[i] + w;

            if (cx >= 0 && cx < n && cy >= 0 && cy < m){
                if (dist[cx][cy] == dist[v][w] - 1){
                    if (pos_X[i] == -1 && pos_Y[i] == 0){
                        caminho.push_back('D');
                    }
                    else if (pos_X[i] == 1 && pos_Y[i] == 0){
                        caminho.push_back('U');
                    }
                    else if (pos_X[i] == 0 && pos_Y[i] == -1){
                        caminho.push_back('R');
                    }
                    else caminho.push_back('L');
    
                    q.push({cx, cy});
                    break;
                }
            }

        }

    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    s.resize(n);
    vis.resize(n, vector<bool> (m));
    dist.resize(n, vector<int> (m, -1));

    for (int i = 0; i < n; i++){
        cin >> s[i];
        for (int j = 0; j < m; j++){
            if (s[i][j] == 'A') start = {i, j};
            if (s[i][j] == 'B') fim = {i, j};
        }
    }

    bfs(start.first, start.second);

    if (ok){
        cout << "YES" << "\n";
        cout << dist[fim.first][fim.second] << "\n";

        reconstruir(fim.first, fim.second);

        reverse(caminho.begin(), caminho.end());
        cout << caminho << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}