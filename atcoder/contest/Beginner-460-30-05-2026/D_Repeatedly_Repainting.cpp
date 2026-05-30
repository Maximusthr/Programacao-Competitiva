#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<char>> s(n, vector<char> (m, '.'));

    int dx[8] = {-1, 0, 0, 1, 1, -1, 1, -1};
    int dy[8] = {0, -1, 1, 0, -1, 1, 1, -1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == '#'){
                for (int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isValid(x, y) && mat[x][y] == '.'){
                        s[x][y] = '#';
                    }
                }
            }
        }
    }

    mat = move(s);

    vector<vector<int>> dist(n, vector<int> (m, INF+1));

    struct P {
        int u, v, w;
    };

    queue<P> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == '#'){
                dist[i][j] = 0;
                q.push({i, j, 0});
            }
        }
    }

    while(!q.empty()){
        int u = q.front().u;
        int v = q.front().v;
        int w = q.front().w;
        q.pop();

        for (int i = 0; i < 8; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if (isValid(x, v) && dist[x][y] == INF+1){
                dist[x][y] = w + 1;
                q.push({x, y, w + 1});
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dist[i][j] & 1) cout << '#';
            else cout << '.';
        }
        cout << "\n";
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}