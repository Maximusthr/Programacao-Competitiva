#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    
    vector<ll> odd, even;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] % 2) {
            odd.push_back(arr[i]);
        }
        else {
            even.push_back(arr[i]);
        }
    }

    if (odd.size() == 0){
        for (int i = 0; i < n; i++){
            cout << 0 << " \n"[i == n-1];
        }
        return;
    }


    sort(odd.begin(), odd.end(), greater<ll>());
    sort(even.begin(), even.end(), greater<ll>());

    vector<ll> prefix(even.size() + 1);
    for (int i = 0; i < even.size(); i++){
        prefix[i+1] = prefix[i] + even[i];
    }

    vector<ll> ans;

    // se odd = odd -> podemos pegar 1 impar e o resto dos pares
    // se odd = par -> resultado final = 0
    // tento deixar a qtd de impar o maior possivel

    // se odd virar par, entao deu ruim

    int k = 1;
    ll sum_even = 0;
    int anterior = 0;
    for (int i = 0; i < n; i++){
        if (i == 0){
            ans.push_back(odd[0]);
            k++;
            continue;
        }

        if (even.size() >= k-1){
            ans.push_back(odd[0] + prefix[k-1]);
            anterior = k-1;
        }
        else {
            // precisamos tirar uma quantidade de impares proporcionais
            // para cada 2 impares -> 1 par é removido

            int sobra = k - (int)even.size();

            // se sobra é impar, basta pegar 2 impares e ta tudo ok
            // se sobra é par, temos que tirar o ultimos par e colocar mais um impar

            if (sobra % 2 == 0){
                if (even.size() == 0){
                    ans.push_back(0);
                }
                else if (anterior == 0) {
                    // do nothing
                    ans.push_back(0); // odd + odd = even
                }
                else if (sobra == odd.size()){
                    ans.push_back(0);
                }
                else {
                    ans.push_back(odd[0] + prefix[anterior-1]);
                }
            }
            else {
                ans.push_back(odd[0] + prefix[anterior]);
            }
        }
        k++;
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}