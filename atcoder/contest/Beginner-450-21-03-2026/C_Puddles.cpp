#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    vector<vector<bool>> vis(n, vector<bool>(m));

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};

    bool pode = true;
    auto dfs = [&](auto &&self, int u, int v) -> void {
        if (!vis[u][v]) vis[u][v] = true;

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;
            if (isValid(cx, cy)){
                if (!vis[cx][cy] && arr[cx][cy] == '.'){
                    self(self, cx, cy);
                }
            }
            else {
                pode = false;
            }
        }
    };

    int comp = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && arr[i][j] == '.'){
                comp++;
                pode = true;
                dfs(dfs, i, j);
                if (!pode){
                    comp--; 
                }
            }
        }
    }

    cout << comp << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}