#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        bool ok = true;
        bool acionado = false;
        int contador = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] == 1 && !acionado && contador == 0) {
                acionado = true;
            }
            if (acionado){
                contador++;
            }
            if (contador == k && acionado){
                acionado = false;
                continue;
            }
            if (contador == k && arr[i] == 1){
                ok = false;
                break;
            } 
        }

        if (ok) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}