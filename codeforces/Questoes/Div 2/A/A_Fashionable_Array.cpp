#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    // 2 pares ou 2 impares
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 2){
        if ((arr[0] + arr[1]) % 2){
            cout << 1 << "\n";
            return;
        }
    }

    // 1 so impar nao pode
    
    // distancia para o primeiro impar se o proximo for impar
    // ou
    // distancia para o primeiro par se o primeiro for par

    sort(arr.begin(), arr.end());

    if (arr[0] % 2){
        int aux1 = 0, aux2 = 0;

        for (int i = n-1; i > 0; i--){
            if (arr[i] % 2 == 0){
                aux1++;
            }
            else break;
        }

        // 1o impar mas quero par
        for (int i = 0; i < n; i++){
            if (arr[i] % 2) aux2++;
            else break;
        }
        for (int i = n-1; i >= 0; i--){
            if (arr[i] % 2) aux2++;
            else break;
        }

        cout << min(aux1, aux2) << "\n";
    }
    else {
        int aux = 0;
        for (int i = n-1; i > 0; i--){
            if (arr[i] % 2){
                aux++;
            }
            else break;
        }

        int aux2 = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] % 2 == 0) aux2++;
            else break;
        }
        for (int i = n-1; i >= 0; i--){
            if (arr[i] % 2 == 0) aux2++;
            else break;
        }

        cout << min(aux, aux2) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}