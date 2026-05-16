#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct P {
    int x, y, dir, qtd, passos;
};

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> arr(n, vector<char> (m));
    pair<int, int> st, end;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'S') st = {i, j};
            else if (arr[i][j] == 'T') end = {i, j};
        }
    }

    bool vis[n][m][4][4];
    memset(vis, 0, sizeof(vis));

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#');
    };

    queue<P> q;
    q.push({st.first, st.second, 0, 0, 0});

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int qtd = q.front().qtd;
        int pas = q.front().passos;
        q.pop();

        if (x == end.first && y == end.second){
            cout << pas << "\n";
            return;
        }

        for (int i = 0; i < 4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (isValid(cx, cy)){
                if (dir == i){
                    if (qtd + 1 == 4) continue;
                    if (vis[cx][cy][i][qtd + 1]) continue;

                    vis[cx][cy][i][qtd + 1] = true;
                    q.push({cx, cy, i, qtd + 1, pas + 1});
                }
                else if (!vis[cx][cy][i][1]) {
                    vis[cx][cy][i][1] = true;
                    q.push({cx, cy, i, 1, pas + 1});
                } 
            }
        }
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}