#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < m);
    };

    vector<vector<int>> vis(n, vector<int> (m));
    bool ok = false;
    auto dfs = [&](auto &&self, int x, int y, int p_x, int p_y) -> void {
        if (vis[x][y] == 0){
            vis[x][y] = 1;
        }

        for (int i = 0; i < 4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (p_x == cx && p_y == cy) continue;
            
            if (isValid(cx, cy) && arr[cx][cy] == arr[x][y]){
                if (vis[cx][cy] == 0) self(self, cx, cy, x, y);
                else if (vis[cx][cy] == 1){
                    ok = true;
                    return;
                }
            }
        }
        vis[x][y] = 2;
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (vis[i][j] == 0){
                dfs(dfs, i, j, -1, -1);
                if (ok){
                    cout << "Yes" << "\n";
                    return;
                }
            }
        }
    }
    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}