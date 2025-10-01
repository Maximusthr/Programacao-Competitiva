#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> mat(n);

    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }

    // i = 1a linha
    // j = n linha
    // a = 1a coluna
    // b = n coluna

    int ans = 0;
    int i = 0, j = n-1, a = 0, b = m-1;
    while (i < j && a < b){
        string aux;

        // 1a linha
        for (int va = a; va < b; va++){
            aux += mat[i][va];
        }

        // last coluna
        for (int vi = i; vi < j; vi++){
            aux += mat[vi][b];
        }

        // last linha
        for (int vb = b; vb > a; vb--){
            aux += mat[j][vb];
        }

        // 1a coluna
        for (int vj = j; vj > i; vj--){
            aux += mat[vj][a];
        }

        int tam = (int)aux.size();
        aux += aux;
        for (int k = 0; k+3 < tam+3; k++){
            string x = aux.substr(k, 4);
            if (x == "1543") ans++;
        }

        i++, j--, a++, b--;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}