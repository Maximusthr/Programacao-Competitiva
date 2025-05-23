#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    
    vector<int> c(m);
    for (auto &i : c) cin >> i;
      
    vector<int> pos(n);
    for (int i = 0; i < k; i++){
        int ci, p; cin >> ci >> p;
        pos[p-1] = ci;
        if (ci == 1) {
            cout << p << "\n";
            return;
        }
    }
    
    // 1 nao esta na hierarquia
    vector<bool> vis(m);
    for (int i = 0; i < m; i++){
        bool found = false;
        int index = 0;
        for (int j = 0; j < n; j++){
            if (c[i] == pos[j]) {
                index = j;
                found = true;
                vis[i] = true;
                break;
            }
        }
    
        if (found){
            int aux = i;
            for (int k = index; k >= 0, aux >= 0; k--){
                if (pos[k] == 0 && !vis[aux]) {
                    pos[k] = c[aux];
                    vis[aux] = true; 
                    aux--;
                }
                else if (vis[aux]){
                    aux--;
                    k++;
                }
            }
        }
    }
    
    // caso o 1 esteja na hierarquia, defino todas as hierarquias
    bool ok = false;
    for (int i = 0; i < m; i++){
        if (c[i] == 1){
            ok = true;
            break;
        }
    }
    if (ok){
        int aux = 0;
        for (int i = 0; i < n, aux < m; i++){
            if (pos[i] == 0 && !vis[aux]){
                pos[i] = c[aux];
                vis[aux] = true;
                aux++;
            }
            else if ((pos[i] == 0 && vis[aux]) || (pos[i] == c[aux])){
                aux++;
                //i--;
            }
        }
    }

    // caso o 1 tenha sido definido
    for (int i = 0; i < n; i++){
        if (pos[i] == 1){
            cout << i + 1 << "\n";
            return;
        }
    }
    
    // caso o 1 nao tenha sido definido, encontro o 0 mais próximo
    for (int i = 0; i < n; i++){
        if (pos[i] == 0){
            cout << i + 1 << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    solve();
}
