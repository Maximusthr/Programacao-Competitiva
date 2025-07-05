#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<string> g(n);
vector<vector<bool>> vis(n);

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, -1, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && g[x][y] == '#');
}

int area = 0, perim = 0;
// pair<int, int> dfs(int u, int v){
//     if (!vis[u][v]) vis[u][v] = true;

//     area++;
//     for (int i = 0; i < 4; i++){
//         int cx = u + pos_X[i];
//         int cy = v + pos_Y[i];

//         if (isValid(cx, cy)){
//             dfs(cx, cy);
//         }
//         else if (!isValid(cx, cy)){
//             if (cx >= 0 && cx < n && cy >= 0 && cy < n && vis[cx][cy]) continue;
//             perim++;
//         }
//     }

//     return {area, perim};
// }

pair<int, int> bfs(int u, int v){

    queue<pair<int, int>> q;
    q.push({u, v});
    while(!q.empty()){
        pair<int, int> a = q.front();
        q.pop();
        
        if (vis[a.first][a.second]) continue;
        vis[a.first][a.second] = true;

        area++;
        for (int i = 0; i < 4; i++){
            int cx = a.first + pos_X[i];
            int cy = a.second + pos_Y[i];

            if (isValid(cx, cy)){
                q.push({cx, cy});
            }
            else {
                if (cx >= 0 && cx < n && cy >= 0 && cy < n && vis[cx][cy]) continue;
                perim++;
            }
        }
    }

    return {area, perim};
}

void solve(){
    cin >> n;

    g.resize(n);
    vis.resize(n, vector<bool> (n));
    for (int i = 0; i < n; i++) cin >> g[i];

    vector<pair<int, int>> valores;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!vis[i][j] && g[i][j] == '#'){
                valores.push_back(bfs(i, j));
                area = 0, perim = 0;
            }
        }
    }

    sort(valores.begin(), valores.end(), [&](pair<int, int> &x, pair<int, int> &y){
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });

    cout << valores[0].first << " " << valores[0].second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    solve();
}