#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};

int n, m;
vector<vector<char>> g;
vector<vector<bool>> can;
vector<vector<bool>> vis;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m && g[x][y] != '?');
}

bool dfs(int u, int v){
    if (!vis[u][v]){
        vis[u][v] = true;
    }

    if (g[u][v] == 'U'){
        if (u-1 < 0) {
            can[u][v] = 1;
            return true;
        }
        else if (isValid(u-1, v) && !vis[u-1][v]) {
            can[u][v] = dfs(u-1, v);
        }
        else if (isValid(u-1, v)){
            if (can[u-1][v]) can[u][v] = 1;
        }
    }
    else if (g[u][v] == 'D'){
        if (u+1 >= n) {
            can[u][v] = 1;
            return true;
        }
        else if (isValid(u+1, v) && !vis[u+1][v]){
            can[u][v] = dfs(u+1, v);
        }
        else if (isValid(u+1, v)){
            if (can[u+1][v]) can[u][v] = 1;
        }
    }
    else if (g[u][v] == 'L'){
        if (v-1 < 0) {
            can[u][v] = 1;
            return true;
        }
        else if (isValid(u, v-1) && !vis[u][v-1]){
            can[u][v] = dfs(u, v-1);
        }
        else if (isValid(u, v-1)){
            if (can[u][v-1]) can[u][v] = 1;
        }
    }
    else {
        if (v+1 >= m) {
            can[u][v] = 1;
            return true;
        }
        else if (isValid(u, v+1) && !vis[u][v+1]){
            can[u][v] = dfs(u, v+1);
        }
        else if (isValid(u, v+1)){
            if (can[u][v+1]) can[u][v] = 1;
        }
    }

    if (can[u][v]) return true;
    return false;
}

void solve(){
    cin >> n >> m;
    
    g.resize(n, vector<char> (m));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    vis.resize(n, vector<bool> (m));
    can.resize(n, vector<bool> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && isValid(i, j)){
                dfs(i, j);
            }
        }
    }
    
    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '?'){
                bool pode = false;

                if (i+1 < n && !can[i+1][j]) pode = true;
                if (j+1 < m && !can[i][j+1]) pode = true;
                if (i-1 >= 0 && !can[i-1][j]) pode = true;
                if (j-1 >= 0 && !can[i][j-1]) pode = true;

                if (pode) ans++;
                else can[i][j] = 1;
            }
            else {
                if (!can[i][j]) ans++;
            }
        }
    }

    cout << ans << "\n";

    g.clear();
    can.clear();
    vis.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}