#include <bits/stdc++.h>

using namespace std;

int t; 
const int MAX = 26;
vector<string> g(MAX);
vector<vector<bool>> vis(MAX, vector<bool> (MAX));

int pos_X[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int pos_Y[] = {0, 1, -1, 0, 1, -1, -1, 1};

bool isValid(int x, int y){
    if (x < 0 || y < 0 || x >= t || y >= t) return false;
    return true;
}

void dfs(int u, int v){
    vis[u][v] = true;

    for (int i = 0; i < 8; i++){
        int cx = u + pos_X[i];
        int cy = v + pos_Y[i];

        if (!isValid(cx, cy)) continue;
        if (g[cx][cy] == '1' && !vis[cx][cy]){
            dfs(cx, cy);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int k = 1;
    while(cin >> t){
        for (int i = 0; i < t; i++){
            cin >> g[i];
        }

        int sum = 0;
        for (int i = 0; i < t; i++){
            for (int j = 0; j < t; j++){
                if (!vis[i][j] && g[i][j] == '1'){
                    dfs(i, j);
                    sum++;
                }
            }
        }
        
        cout << "Image number " << k << " contains " << sum << " war eagles." << "\n";

        g.assign(MAX, "");
        vis.assign(MAX, vector<bool> (MAX));
        k++;
    }
}
