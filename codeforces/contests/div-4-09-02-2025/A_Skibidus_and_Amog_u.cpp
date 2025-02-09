#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        string x;
        cin >> x;

        string aux;
        for (int j = 0; j < (int)x.size(); j++){
            if (j == (int)x.size()-2  && x[j] == 'u' && x[j+1] == 's') {
                aux += 'i';
                break;
            }
            else aux += x[j];
        }

        cout << aux << "\n";
    }
}
