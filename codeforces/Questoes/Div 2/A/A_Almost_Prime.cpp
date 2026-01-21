#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int ans = 0;
    for (int j = 4; j <= n; j++){
        int qtd = 0;
        int aux = j;
        for (int i = 2; i <= aux; i++){
            if (aux % i == 0){
                qtd++;
                while (aux % i == 0){
                    aux /= i;
                }
            }
        }   
        if (qtd == 2){
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}