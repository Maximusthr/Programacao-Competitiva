#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

int n;

vector<string> g(MAX);
vector<vector<bool>> vis(MAX, vector<bool> (MAX));

int pos_x[] = {-1, 0, 0, 1};
int pos_y[] = {0, -1, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(int x, int y){
    vis[x][y] = true;

    for (int i = 0; i < 4; i++){
        int cx = x + pos_x[i];
        int cy = y + pos_y[i];

        if (isValid(cx, cy)){
            if (!vis[cx][cy] && (g[cx][cy] == 'x' || g[cx][cy] == '@')) {
                dfs(cx, cy);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    int c = 1;
    while(t--){
        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> g[i];
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!vis[i][j] && g[i][j] == 'x'){
                    ans++;
                    dfs(i, j);
                }
            }
        }

        cout << "Case " << c << ": " << ans << "\n";

        g.assign(MAX, "");
        vis.assign(MAX, vector<bool> (MAX));

        c++;
    }
}
