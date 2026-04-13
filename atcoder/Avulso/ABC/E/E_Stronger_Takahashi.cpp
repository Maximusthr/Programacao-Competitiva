#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    vector<string> s(n);
    for (auto &i : s) cin >> i;

    vector<vector<int>> dist(n, vector<int> (m, INF));

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    struct P {
        int u, v, d;
    };

    deque<P> dq;
    dist[0][0] = 0;
    dq.push_front({0, 0, 0});
    while(!dq.empty()){
        int u = dq.front().u;
        int v = dq.front().v;
        int d = dq.front().d;
        dq.pop_front();

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                if (s[cx][cy] == '.' && d < dist[cx][cy]){
                    dist[cx][cy] = d;
                    dq.push_front({cx, cy, d});
                }
                else {
                    for (int k = -1; k <= 1; k++){
                        for (int l = -1; l <= 1; l++){
                            if (isValid(cx+k, cy+l)){
                                if (d + 1 < dist[cx+k][cy+l]){
                                    dist[cx+k][cy+l] = d + 1;
                                    dq.push_back({cx+k, cy+l, d+1});
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dist[n-1][m-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}