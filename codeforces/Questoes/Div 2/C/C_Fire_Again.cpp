#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    int qq; cin >> qq;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    // vector<vector<int>> g(n, vector<int> (m));
    vector<vector<int>> dist(n, vector<int> (m, -1));

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1);
    };

    queue<pair<int, int>> q;
    for (int i = 0; i < qq; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        q.push({x, y});

        dist[x][y] = 0;
    }

    while (!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = u + dx[i];
            int cy = v + dy[i];

            if (isValid(cx, cy)){
                q.push({cx, cy});
                dist[cx][cy] = dist[u][v] + 1;
            }
        }
    }

    int maior = 0;
    pair<int, int> ans;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dist[i][j] > maior){
                maior = dist[i][j];
                ans = {i, j};
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}

