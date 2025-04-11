#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, d; cin >> n >> m >> d;
    
    vector<int> plat(m+1);
    int qtd_plat = 0;
    for (int i = 1; i <= m; i++){
        cin >> plat[i];
        qtd_plat += plat[i];
    }
    
    vector<int> rio(n+1);
    int pos = 0;
    bool ok = false;

    for (int i = 1; i <= m; i++){
        if (pos + d + qtd_plat > n + 1){
            for (int j = pos + 1; j < pos + 1 + plat[i]; j++){
                rio[j] = i;
            }
            pos += plat[i];
            qtd_plat -= plat[i];
        }
        else {
            for (int j = pos + d; j < pos + d + plat[i]; j++){
                rio[j] = i;
            }
            pos += d + plat[i] - 1;
            qtd_plat -= plat[i];
        }
    }

    if (pos + d >= n+1) ok = true;

    if (ok) {
        cout << "YES" << "\n";
        for (int i = 1; i < n+1; i++){
            cout << rio[i] << " ";
        }
        cout << "\n";
    }
    else cout << "NO" << "\n";
}
