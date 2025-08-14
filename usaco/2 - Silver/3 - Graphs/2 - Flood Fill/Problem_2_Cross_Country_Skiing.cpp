#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int m, n;
vector<vector<int>> g;
vector<vector<int>> reff;
vector<vector<bool>> vis;
vector<pair<int, int>> points;

bool isValid(int x, int y){
    return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]);
}

int X[] = {1, 0, 0, -1};
int Y[] = {0, 1, -1, 0};

void dfs(int u, int v, int mid){
    if (!vis[u][v]) vis[u][v] = true;

    for (int i = 0; i < 4; i++){
        int x = X[i] + u;
        int y = Y[i] + v;
        if (isValid(x, y)){
            if (g[x][y] >= g[u][v]){
                if (g[u][v] + mid >= g[x][y]){
                    dfs(x, y, mid);
                }
            }
            else if (g[x][y] < g[u][v]){
                if (g[u][v] - mid <= g[x][y]){
                    dfs(x, y, mid);
                }
            }
        }
    }

}

bool ok(int mid){
    dfs(points[0].first, points[0].second, mid);

    int temp = 0;
    for (auto &[x, y] : points){
        if (vis[x][y]) temp++;
    }

    return temp == points.size();
}

void solve(){
    cin >> m >> n;

    g.resize(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }

    reff.resize(m, vector<int>(n));
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> reff[i][j];
            if (reff[i][j] == 1) points.push_back({i, j});
        }
    }

    vis.resize(m, vector<bool>(n));

    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid+1;

        vis.assign(m, vector<bool>(n));
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    solve();
}