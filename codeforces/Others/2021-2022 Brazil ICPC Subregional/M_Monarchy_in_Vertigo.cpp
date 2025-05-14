// Inspiração https://github.com/jonh14lk/Competitive_Programming/blob/master/Problem%20Solving/Subregional%202021/m.cpp

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+1;

vector<int> g[MAX];
vector<bool> vis(MAX);
//vector<int> adj[MAX];
//bool vis[MAX];
queue<int> fila;

void dfs(int u){
    fila.push(u);
    for (auto v : g[u]){
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> q;

    int id = 1;
    while(n--){
        int x, y; cin >> x >> y;
        y--;
        if (x == 1){
            g[y].push_back({id++});
        }
        else {
            q.push_back(y);
        }
    }
    dfs(0);

    for (int i = 0; i < (int)q.size(); i++){
        vis[q[i]] = 1; // defino que morreu
        while(vis[fila.front()]){ // enquanto for morto eu tiro da fila de sucessão
            fila.pop();            
        } 
        cout << fila.front() + 1 << "\n";
    }
}