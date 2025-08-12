#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> moedas;

int valor[1000010];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, x; cin >> n >> x;

    moedas.resize(n);

    memset(valor, INF, sizeof(valor));

    for (auto &i : moedas) cin >> i;

    valor[0] = 0;
    for (int i = 1; i <= x; i++){
        for (auto &c : moedas){
            if (i - c >= 0){
                valor[i] = min(valor[i], valor[i-c] + 1);
            }
        }
    }   

    if (valor[x] == INF) cout << -1 << "\n";
    else cout << valor[x] << "\n";

}