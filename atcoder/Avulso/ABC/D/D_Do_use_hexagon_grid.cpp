#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int v = 2005;

void solve(){
    int n; cin >> n;

    vector<vector<bool>> vis(v, vector<bool> (v));
    vector<vector<bool>> pode(v, vector<bool> (v));
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        x += 1000;
        y += 1000;
        arr[i] = {x, y};
        pode[x][y] = 1;
    }

    int dx[] = {-1, -1, 0, 0, 1, 1};
    int dy[] = {-1, 0, -1, 1, 0, 1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x <= v && y >= 0 && y <= v);
    };

    auto dfs = [&](auto &&self, int u, int v) -> void {
        if (!vis[u][v]) vis[u][v] = true;

        for (int i = 0; i < 6; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                if (!vis[cx][cy] && pode[cx][cy]){
                    self(self, cx, cy);
                }
            }
        }
    };
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        auto [a, b] = arr[i];
        if (!vis[a][b]){
            ans++;
            dfs(dfs, a, b);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}