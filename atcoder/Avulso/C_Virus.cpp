#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2005;

int n, dist; 

struct ent {
    int a;
    int b;
};

bool valido(ent a, ent b){
    return (a.a - b.a) * (a.a - b.a) + (a.b - b.b) * (a.b - b.b) <= dist;
}

vector<pair<int, int>> g[MAX][MAX];
vector<vector<bool>> vis;
map<pair<int, int>, string> ans;

void dfs(int x, int y){
    if (!vis[x][y]) vis[x][y] = true;

    ans[{x, y}] = "Yes";

    for (auto u : g[x][y]){
        if (!vis[u.first][u.second]){
            dfs(u.first, u.second);
        }
    }
}

void solve(){

    cin >> n >> dist;

    dist *= dist;

    vector<ent> coord(n);
    for (int i = 0; i < n; i++){
        cin >> coord[i].a >> coord[i].b;
        coord[i].a += 1000;
        coord[i].b += 1000;
    }

    vis.assign(MAX, vector<bool> (MAX));

    for (int i = 0; i < n; i++){
        auto &u = coord[i];
        for (int j = 0; j < n; j++){
            if (i == j) continue;

            auto &v = coord[j];

            if (valido(u, v)){
                g[u.a][u.b].push_back({v.a, v.b});
            }
        }
    }   

    dfs(coord[0].a, coord[0].b);

    for (int i = 0; i < n; i++){
        if (ans[{coord[i].a, coord[i].b}] == "Yes"){
            cout << "Yes" << "\n";
        }
        else cout << "No" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}