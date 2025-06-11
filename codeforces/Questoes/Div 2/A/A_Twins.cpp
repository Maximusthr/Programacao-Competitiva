#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> arr;
    int sum_aux = 0;
    for (int i = 0; i < qtd; i++){
        int aux; cin >> aux;
        sum_aux += aux;
        arr.push_back(aux);
    }
    
    sort(arr.rbegin(), arr.rend());

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < qtd; i++){
        sum += arr[i];
        sum_aux -= arr[i];
        ans++;
        if (sum > sum_aux){
            cout << ans << "\n";
            break;
        }
    }
}
