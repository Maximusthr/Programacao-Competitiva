#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m; 
vector<string> s(n);
vector<vector<bool>> vis(n, vector<bool> (m));

int pos_x[] = {-1, 0, 0, 1};
int pos_y[] = {0, 1, -1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && s[x][y] == '.');
}

void dfs(int u, int v){
    if (!vis[u][v]) vis[u][v] = true;

    for (int i = 0; i < 4; i++){
        int cx = u + pos_x[i];
        int cy = v + pos_y[i];

        if (isValid(cx, cy)) dfs(cx, cy);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    s.resize(n);
    vis.resize(n, vector<bool> (m));

    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && s[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << "\n";
}