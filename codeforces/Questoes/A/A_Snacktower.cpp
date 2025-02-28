#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    int arr[qtd+1];
    for (int i = 1; i <= qtd; i++){
        cin >> arr[i];
    }

    // busca binaria para achar o maior valor depois dos já utilizados
    
    int maior = qtd;
    int menor = maior;
    vector<int> elem;
    for (int i = 1; i <= qtd; i++){
        if (arr[i] == maior) {
            elem.push_back(arr[i]);
            sort(elem.rbegin(), elem.rend());

            for (int j = 0; j < (int)elem.size(); j++){
                cout << elem[j] << " ";
            }
            cout << "\n";
            maior =  *lower_bound(elem.rbegin(), elem.rend(), menor) - 1;
            menor = maior;
            elem.clear();
        }
        else {
            elem.push_back(arr[i]);
            cout << "\n";
        }
    }
}
