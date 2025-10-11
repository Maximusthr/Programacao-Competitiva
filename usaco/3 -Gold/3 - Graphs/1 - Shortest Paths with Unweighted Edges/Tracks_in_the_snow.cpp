#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;

vector<string> g;

int X[4] = {0, -1, 1, 0};
int Y[4] = {-1, 0, 0, 1};

bool is_Valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '.');
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    g.resize(n);

    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    vector<vector<int>> depth(n, vector<int> (m));

    deque<pair<int, int>> q;
    q.push_back({0, 0});
    depth[0][0] = 1;

    int ans = 1;

    while(!q.empty()){
        auto [u, v] = q.front();

        q.pop_front();

        ans = max(ans, depth[u][v]);

        for (int i = 0; i < 4; i++){
            int cx = X[i] + u;
            int cy = Y[i] + v;

            if (is_Valid(cx, cy) && depth[cx][cy] == 0){
                if (g[cx][cy] == g[u][v]){
                    depth[cx][cy] = depth[u][v];
                    q.push_front({cx, cy});
                }
                else {
                    depth[cx][cy] = depth[u][v] + 1;
                    q.push_back({cx, cy});
                }
            }
        }
    }

    cout << ans << "\n";
}