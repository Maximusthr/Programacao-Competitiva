#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    x0--, y0--, x1--, y1--;

    if (x0 == x1 && y0 == y1) {
        cout << 0 << "\n";
        return;
    }

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.');
    };

    struct P {
        int u, v, kk, dir;
    };

    int dist[n][m][4];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int l = 0; l < 4; l++){
                dist[i][j][l] = INF;
            }
        }
    }

    deque<P> deq;
    dist[x0][y0][0] = 0;
    dist[x0][y0][1] = 0;
    dist[x0][y0][2] = 0;
    dist[x0][y0][3] = 0;
    deq.push_front({x0, y0, 0, 0});
    deq.push_front({x0, y0, 0, 1});
    deq.push_front({x0, y0, 0, 2});
    deq.push_front({x0, y0, 0, 3});

    while(!deq.empty()){
        auto [u, v, kk, dir] = deq.front();
        deq.pop_front();

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                // se eu to na mesma direcao e o k for ok
                // eu uso ela
                if (i == dir){
                    if (dist[u][v][dir] < dist[cx][cy][i] && kk < k){
                        dist[cx][cy][i] = dist[u][v][dir];
                        deq.push_front({cx, cy, kk + 1, dir});
                        continue;
                    }
                }

                // se nao der, muda o k e a dir
                if (dist[u][v][dir] + 1 < dist[cx][cy][i]){
                    dist[cx][cy][i] = dist[u][v][dir] + 1;
                    deq.push_back({cx, cy, 1, i});
                }
            }
        }
    }

    int ans = min({dist[x1][y1][0], dist[x1][y1][1], dist[x1][y1][2], dist[x1][y1][3]});
    cout << (ans == INF ? -1 : ans + 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}