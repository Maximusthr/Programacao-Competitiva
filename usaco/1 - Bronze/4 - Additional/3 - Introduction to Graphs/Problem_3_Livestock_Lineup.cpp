#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 8;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

map<string, int> name;
vector<int> arr;

void dfs(int u){
    vis[u] = true;

    cout << cows[u] << "\n";

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    // freopen("lineup.in", "r", stdin);
    // freopen("lineup.out", "w", stdout);
    
    for (int i = 0; i < MAX; i++) name[cows[i]] = i;

    int n; cin >> n;

    for (int i = 0; i < n; i++){
        string ini, lixo, fim;
        cin >> ini >> lixo >> lixo >> lixo >> lixo >> fim;
        g[name[fim]].push_back(name[ini]);
        g[name[ini]].push_back(name[fim]);
    }

    for (int i = 0; i < MAX; i++){
        if (!vis[i] && g[i].size() <= 1){
            dfs(i);
        }
    }
}
