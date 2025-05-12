#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1005;
int n, m;

vector<string> g(MAX);
bool vis[MAX][MAX];
int dist[MAX][MAX];

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, 1, -1, 0};

bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && g[x][y] != '#' && !vis[x][y];
}

void bfs_ms(vector<pair<int, int>> ms){
    // se usar vector -> usar o assign
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);

    queue<pair<int, int>> q;
    for (auto s : ms){
        q.push(s);
        vis[s.first][s.second] = true;
        dist[s.first][s.second] = 0;
    }

    while(!q.empty()){
        pair<int, int> v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int x = v.first + pos_X[i];
            int y = v.second + pos_Y[i];

            if (isValid(x, y)){
                q.push({x, y});
                vis[x][y] = true;
                dist[x][y] = dist[v.first][v.second] + 1;
            }
        }
    }
}

int bfs(pair<int, int> s){
    memset(vis, 0, sizeof vis);

    queue<pair<int ,int>> q;
    q.push(s);
    vis[s.first][s.second] = true;
    dist[s.first][s.second] = 0;

    while(!q.empty()){
        pair<int, int> v = q.front();
        q.pop();

        if (v.first == 0 || v.second == 0 || v.first == n-1 || v.second == m-1){
            return dist[v.first][v.second] + 1;
        }

        for (int i = 0; i < 4; i++){
            int x = pos_X[i] + v.first;
            int y = pos_Y[i] + v.second;

            if (isValid(x, y) && dist[v.first][v.second] + 1 < dist[x][y]){
                q.push({x, y});
                vis[x][y] = true;
                dist[x][y] = dist[v.first][v.second] + 1;
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        cin >> m >> n; // invertido
        
        for (int i = 0; i < n; i++){
            cin >> g[i];
        }
        
        //bfs_ms(ms) -> multisorce
        //bfs(s) -> normal
        vector<pair<int, int>> ms;
        pair<int, int> s;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (g[i][j] == '*') ms.push_back({i, j});
                if (g[i][j] == '@') s = {i, j};
            }
        }

        bfs_ms(ms); // definir as posições de matriz de dist

        int ans = bfs(s); // retorna a resposta

        if (ans == -1) cout << "IMPOSSIBLE" << "\n";
        else cout << ans << "\n";
    }
}