#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<bool>> vis;
vector<vector<int>> dist;

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, -1, 1, 0};

int n, m;

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

int bfs(vector<string> &labir){
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while(!q.empty()){
        auto [v, w] = q.front();
        q.pop();
        if (!vis[v][w]) vis[v][w] = true;
    
        if (v == n-1 && w == m-1){
            return dist[v][w];
        }
    
        for (int i = 0; i < 4; i++){
            int cx = pos_X[i] + v;
            int cy = pos_Y[i] + w;
    
            if (isValid(cx, cy) && labir[cx][cy] != '#'){
                q.push({cx, cy});
                vis[cx][cy] = true;
                dist[cx][cy] = dist[v][w] + 1;
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    vis.assign(n, vector<bool> (m));
    dist.assign(n, vector<int> (m, -1));

    vector<string> path1(n);
    for (auto &i : path1) cin >> i;

    int cam1 = bfs(path1);

    vector<string> path2(n);
    for (auto &i : path2) cin >> i;

    vis.assign(n, vector<bool> (m));
    dist.assign(n, vector<int> (m, -1));

    int cam2 = bfs(path2);
    
    vector<string> lab(n, string(m, '.'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (path1[i][j] == path2[i][j]) lab[i][j] = path1[i][j];
            else lab[i][j] = '#';
        }
    }

    vis.assign(n, vector<bool> (m));
    dist.assign(n, vector<int> (m, -1));
    int cam3 = bfs(lab);

    if (cam1 == cam2 && cam1 == cam3 && cam1 != -1) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
