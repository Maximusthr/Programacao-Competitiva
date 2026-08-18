const int INF = 0x3f3f3f3f;

int n;
vector<vector<int>> g(n, vector<int> (n, INF));
for (int i = 0; i < n; i++){
    g[i][i] = 0;
}

// ciclo negativo no grafo:

for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        for (int t = 0; t < n; t++){
            if (g[i][t] < INF && g[t][j] < INF && g[t][t] < 0){
                g[i][j] = -INF;
            }    
        }
    }
}