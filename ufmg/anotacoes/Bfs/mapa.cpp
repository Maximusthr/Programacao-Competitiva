// BFS EM GRID 

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 110;

int n, m;
vector<string> g(MAX);
vector<vector<bool>> vis(MAX, vector<bool> (MAX));

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, 1, -1 , 0};

bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 'H' && !vis[x][y];
}

pair<int, int> bfs(int u, int v){
    vis[u][v] = true;

    queue<pair<int, int>> q;
    q.push({u, v});

    pair<int, int> w;
    while(!q.empty()){
        w = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int x = w.first + pos_X[i];
            int y = w.second + pos_Y[i];

            if (isValid(x, y)){
                q.push({x, y});
                vis[x][y] = true;
            }
        }
    }

    return w; // sera o ultimo elemento a ser visitado e que sera valido
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    pair<int, int> s;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'o'){
                s = {i, j};
            }
        }
    }

    pair<int, int> ans = bfs(s.first, s.second);

    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
}
