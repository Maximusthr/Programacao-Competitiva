#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m));
    pair<int, int> start, end;
    vector<pair<int, int>> bred;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j] == 'S') start = {i, j};
            else if (mat[i][j] - '0' >= 1 && mat[i][j] - '0' <= 9) bred.push_back({i, j});
            else if (mat[i][j] == 'E') end = {i, j};
        }
    }

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    auto isValid = [&](int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != 'T');
    };

    queue<pair<int, int>> q;
    q.push(end);
    vector<vector<int>> dist(n, vector<int> (m, -1));
    dist[end.first][end.second] = 0;
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy) && dist[cx][cy] == -1){
                dist[cx][cy] = dist[u][v] + 1;
                q.push({cx, cy});
            }
        }
    }

    q.push(start);
    vector<vector<int>> time(n, vector<int> (m, -1));
    time[start.first][start.second] = 0;
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;

        q.pop();

        if (end.first == u && end.second == v) {
            int time_end = time[u][v];
            int ans = 0;
            for (int i = 0; i < bred.size(); i++){
                if (dist[bred[i].first][bred[i].second] == -1) continue;
                if (dist[bred[i].first][bred[i].second] <= time_end){
                    ans += mat[bred[i].first][bred[i].second] - '0';
                }
            }
            cout << ans << "\n";
            return;
        }

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy) && time[cx][cy] == -1){
                time[cx][cy] = time[u][v] + 1;
                q.push({cx, cy});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}