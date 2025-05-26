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

        string s; cin >> s;

        int qtd_one = 0, qtd_zero = 0;

        for (int i = 0; i < n; i++){
            if (s[i] == '1') qtd_one++;
            else qtd_zero++;
        }

        int pares = (qtd_one/2) + (qtd_zero/2);
        int dif = abs((qtd_one/2) - (qtd_zero/2));

        if ((pares % 2) && (k % 2)){
            if (pares >= k){
                if (dif <= k) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
            else cout << "NO" << "\n";
        }
        else if (pares % 2 == 0 && k % 2 == 0){
            if (pares >= k){
                if (dif <= k) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
            else cout << "NO" << "\n";
        }
        else cout << "NO" << "\n";
    }
}
