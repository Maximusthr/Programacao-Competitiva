#include <bits/stdc++.h>

using namespace std;

int n, m;

const int MAX = 1e3+1;
vector<string> g(MAX);
vector<vector<bool>> vis(MAX, vector<bool> (MAX)); 

int pos_X[] = {-1, 0, 0, 1};
int pos_Y[] = {0, 1, -1, 0};

bool isValid(int x, int y){
    return !(x >= n || x < 0 || y >= m || y < 0);
}

void dfs(int u, int v){
    vis[u][v] = true;

    for (int i = 0; i < 4; i++){
        int cx = pos_X[i] + u;    
        int cy = pos_Y[i] + v;

        if (!isValid(cx, cy)) continue;
        if (g[cx][cy] == '.' && !vis[cx][cy]){
            dfs(cx, cy);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && g[i][j] != '#'){
                dfs(i, j);
                ans++;
            }     
        }
    }

    cout << ans << "\n";
}
