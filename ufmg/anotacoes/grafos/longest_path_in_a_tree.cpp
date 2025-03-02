//achar a maior distancia da arvore

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4+10;
vector<vector<int>> g(MAX);
int dist[MAX]; // distancia de um ponto ao outro, adicionando -1, pois ele nunca terá sido visitado

void dfs(int v){
    for (auto w : g[v]){
        if (dist[w] == -1){
            dist[w] = dist[v] + 1; // vizinho atual depende do anterior + 1
            dfs(w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;

    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(dist, -1, sizeof dist); // usando no array -> define todo mundo em -1

    dist[0] = 0;
    dfs(0);

    int pos = -1, distmax = -1;
    for (int i = 0; i < n; i++){
        if (dist[i] > distmax) {
            distmax = dist[i];
            pos = i;
        }
    }

    memset(dist, -1, sizeof dist); // volta tudo novamente
    
    dist[pos] = 0;
    dfs(pos);

    int diametro = 0;
    for (int i = 0; i < n; i++){
       diametro = max(diametro, dist[i]);
    }

    cout << diametro << "\n";
}
