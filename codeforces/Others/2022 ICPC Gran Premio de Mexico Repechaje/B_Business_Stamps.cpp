#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

void solve(){
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    int w1, w2; cin >> w1 >> w2;

    x--, y--;
    w1--, w2--;

    vector<vector<int>> arr(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            arr[i][j]--; 
        }
    }

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    struct P {
        int u, v, mask;
    };

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(1024, INF)));

    deque<P> deq;
    dist[x][y][(1 << arr[x][y])] = 1;
    deq.push_front({x, y, (1 << arr[x][y])});

    while(!deq.empty()){
        auto [u, v, mask] = deq.front();
        deq.pop_front();

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                int new_mask = mask | (1 << arr[cx][cy]);
                
                int c = (mask == new_mask) ? 0 : 1;

                if (dist[u][v][mask] + c < dist[cx][cy][new_mask]){
                    dist[cx][cy][new_mask] = dist[u][v][mask] + c;
                    
                    if (c == 0) deq.push_front({cx, cy, new_mask});
                    else deq.push_back({cx, cy, new_mask});
                }
            }
        }
    }

    int ans = INF;
    for (int mask = 0; mask < 1024; mask++){
        ans = min(ans, dist[w1][w2][mask]);
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}