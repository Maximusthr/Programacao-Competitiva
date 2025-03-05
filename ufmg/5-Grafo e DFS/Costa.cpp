#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+10;

int n, m;
vector<string> mat(MAX);
vector<vector<bool>> vis(MAX, vector<bool> (MAX));
vector<vector<bool>> pontos(MAX, vector<bool> (MAX));

int pos_x[] = {-1, 0, 0, 1};
int pos_y[] = {0, 1, -1, 0};

bool isValid(int x, int y){
    return !(x > n || x < 0 || y > m || y < 0);
}

void dfs(int x, int y){
    vis[x][y] = true;

    if (x == n-1 || y == m-1 || x == 0 || y == 0) pontos[x][y] = true;

    for (int i = 0; i < 4; i++){
        int X = x + pos_x[i];
        int Y = y + pos_y[i];

        if (!isValid(X, Y)) continue;
        if (mat[X][Y] == '.') {
            pontos[x][y] = true;
        }
        if (mat[X][Y] == '#' && !vis[X][Y]){
            dfs(X, Y);
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> mat[i];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && mat[i][j] == '#'){
                dfs(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (pontos[i][j]) ans++;
        }
    }

    cout << ans << "\n";

}
