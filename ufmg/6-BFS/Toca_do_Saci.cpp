#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1010;
int n, m; 

//vector<string> g(MAX); contem espaços
char g[MAX][MAX];
vector<vector<bool>> vis(MAX, vector<bool> (MAX));
vector<vector<int>> dist(MAX, vector<int> (MAX));

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, -1, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && (g[x][y] == '1' || g[x][y] == '2'));
}

void bfs(int u, int v){
    queue<pair<int, int>> q;
    q.push({u, v});

    while(!q.empty()){
        pair<int, int> w = q.front();
        vis[w.first][w.second] = true;

        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = pos_X[i] + w.first;
            int cy = pos_Y[i] + w.second;

            if (isValid(cx, cy)){
                vis[cx][cy] = true;
                q.push({cx, cy});
                dist[cx][cy] = dist[w.first][w.second] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    pair<int, int> s;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '3'){
                s = {i, j};
            }
        }
    }
    
    dist[s.first][s.second] = 1;
    bfs(s.first, s.second);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '2'){
                cout << dist[i][j] << "\n";
                break;
            }
        }
    }
}
