#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    string x; cin >> x;

    transform(x.begin(), x.end(), x.begin(), ::tolower);

    map<char, int> alfabeto;

    for (int i = 0; i < qtd; i++){
        alfabeto[x[i]]++;
    }

    if ((int)alfabeto.size() == 26) cout << "YES";
    else cout << "NO";

    cout << "\n";
    
}
