#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int qtd; cin >> qtd;
        string x; cin >> x;

        string traco, linha;

        for (int i = 0; i < qtd; i++){
            if (x[i] == '-') traco += x[i];
            else linha += x[i];
        }

        if ((int)traco.size() <= 1 || ((int)linha.size() == 0)) {
            cout << 0;
        }
        
        // else if (traco.size() % 2 == 0){
        //     cout << 1ll*(traco.size()/2 * traco.size()/2 * linha.size());
        // }
        // else {
        //     cout << 1ll*(traco.size()/2) * (traco.size()/2 + 1) * linha.size();
        // }

        else cout << 1ll*(traco.size()/2 * linha.size() * (traco.size() - traco.size()/2));

        cout << "\n";

    }
}
