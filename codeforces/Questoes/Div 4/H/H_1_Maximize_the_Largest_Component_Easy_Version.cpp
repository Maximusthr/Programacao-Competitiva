#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<string> g;
vector<vector<bool>> vis;
vector<vector<int>> comp;
vector<vector<int>> tipo;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == '#');
}

// precisamos voltar recursivamente e guardar o valor do componente
int qtd = 0;
void dfs(int u, int v, int indice){
    if (!vis[u][v]) {
        vis[u][v] = true;
        tipo[u][v] = indice;
        qtd++;
    }

    for (int i = 0; i < 4; i++){
        int cx = u + dx[i];
        int cy = v + dy[i];

        if (isValid(cx, cy) && !vis[cx][cy]){
            dfs(cx, cy, indice);
        }
    }
}

void solve(){
    cin >> n >> m;

    g.resize(n);
    for (auto &i : g) cin >> i;

    vis.resize(n, vector<bool> (m));

    int cont[2][n][m];
    memset(cont, 0, sizeof(cont));

    comp.resize(n, vector<int> (m));
    tipo.assign(n, vector<int> (m));

    int idx = 1;
    map<int, int> prench;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            qtd = 0;
            if (g[i][j] == '#' && !vis[i][j]){
                dfs(i, j, idx);
                prench[idx] = qtd;
                idx++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int valor = prench[tipo[i][j]];
            comp[i][j] = valor;
        }
    }
    
    // cont[0] = linha
    // cont[1] = coluna

    vis.assign(n, vector<bool> (m, false));
    int ans = 1;
    for (int i = 0; i < 2; i++){
        // 0 linha
        // 1 coluna
        if (i == 0){
            for (int j = 0; j < n; j++){
                map<int, bool> tipos;
                int v = 0;
                int tem = 0;
                for (int k = 0; k < m; k++){
                    if (g[j][k] == '.') tem++;
                    for (int l = 0; l < 4; l++){
                        int cx = dx[l] + j;
                        int cy = dy[l] + k;

                        if (isValid(cx, cy) && !tipos[tipo[cx][cy]]){
                            tipos[tipo[cx][cy]] = 1;
                            v += comp[cx][cy];
                        }
                    }
                }
                v += tem;
                ans = max(ans, v);
            }
        }
        else {
            for (int k = 0; k < m; k++){
                map<int, bool> tipos;
                int v = 0;
                int tem = 0;
                for (int j = 0; j < n; j++){
                    if (g[j][k] == '.') tem++;
                    for (int l = 0; l < 4; l++){
                        int cx = dx[l] + j;
                        int cy = dy[l] + k;
    
                        if (isValid(cx, cy) && !tipos[tipo[cx][cy]]){
                            tipos[tipo[cx][cy]] = 1;
                            v += comp[cx][cy];
                        }
                    }
                }
                v += tem;
                ans = max(ans, v);
            }
        }
    }

    cout << ans << "\n";

    g.clear();
    vis.clear();
    comp.clear();
    tipo.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}