#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<char>> mat;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int X[] = {0, -1, 1, 0};
int Y[] = {1, 0, 0, -1};

vector<pair<int, int>> monsters;
pair<int, int> me;

vector<vector<int>> dist;

void bfs_monsters(){
    queue<pair<int, int>> q;
    for (int i = 0; i < monsters.size(); i++){
        auto [u, v] = monsters[i];
        q.emplace(u, v);
        dist[u][v] = 0;
    }

    while (!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = u + X[i];
            int cy = v + Y[i];

            if (isValid(cx, cy) && mat[cx][cy] == '.'){
                if (dist[cx][cy] > dist[u][v] + 1){
                    dist[cx][cy] = dist[u][v] + 1;
                    q.emplace(cx, cy);
                }
            }
        }
    }
}

string bfs_me(){
    vector<vector<pair<int, int>>> pai(n, vector<pair<int, int>> (m));

    queue<pair<int, int>> q;
    q.emplace(me.first, me.second);
    dist[me.first][me.second] = 0;

    pair<int, int> fim = {-1, -1};

    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        if (u == n-1 || v == m-1 || u == 0 || v == 0){
            fim = {u, v};
            break;
        }

        for (int i = 0; i < 4; i++){
            int cx = u + X[i];
            int cy = v + Y[i];

            if (isValid(cx, cy)){
                if (mat[cx][cy] != 'M' && mat[cx][cy] != '#'){
                    if (dist[cx][cy] > dist[u][v] + 1){
                        dist[cx][cy] = dist[u][v] + 1;
                        pai[cx][cy] = {u, v};
                        q.emplace(cx, cy);
                    }
                }
            }
        }
    }

    if (fim.first == -1){
        return "N";
    }

    string path;
    for (int i = fim.first, j = fim.second; ;){
        int u = i, v = j;
        i = pai[u][v].first, j = pai[u][v].second;

        if (u - i == -1) path.push_back('U');
        else if (u - i == 1) path.push_back('D');
        else if (v - j == -1) path.push_back('L');
        else path.push_back('R');

        if ((i == me.first && j == me.second) || (i == 0 && j == 0)) {
            break;
        }
    }
    reverse(path.begin(), path.end());

    return path;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    mat.resize(n, vector<char> (m));
    dist.resize(n, vector<int> (m, INF));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];

            if (mat[i][j] == 'M') {
                monsters.emplace_back(i, j);
            }
            else if (mat[i][j] == 'A') me = {i, j};
        }
    }

    if (me.first == n-1 || me.second == m-1 || me.first == 0 || me.second == 0){
        cout << "YES" << "\n";
        cout << "0" << "\n";
        return 0;
    }

    bfs_monsters();
    string ans = bfs_me();

    if (ans[0] == 'N'){
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
}