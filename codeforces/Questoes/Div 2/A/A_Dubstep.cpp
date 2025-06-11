#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;
    int tamanho = (int) x.size();

    vector<string> words;

    string aux;
    bool ok = false;
    for (int i = 0; i < tamanho; i++){
        if (x[i] == 'W'){
            if (i+1 < tamanho && i+2 < tamanho){
                if (x[i+1] == 'U' && x[i+2] == 'B'){
                    ok = true;
                    i += 2; // soma 2, pois no i++ será somado mais um valor
                }               
            }
        
            if (ok){
                if ((int)aux.size() > 0) words.push_back(aux);
                aux.clear();
                ok = false;
            }
            else aux += x[i];
        } else {
            aux += x[i];
        }
        if (i == tamanho-1) words.push_back(aux);
    }

    for (int i = 0; i < (int)words.size(); i++)
        cout << words[i] << " ";
    
    cout << "\n";
}
