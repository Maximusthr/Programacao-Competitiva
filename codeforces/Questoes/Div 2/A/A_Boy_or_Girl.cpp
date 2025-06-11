#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    set<char> a;
    string aux; cin >> aux;

    for (int i = 0; i < (int)aux.size(); i++){
        a.insert(aux[i]);
    }

    int tam = (int)a.size();

    if (tam % 2 == 1) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";

    cout << "\n";
}
