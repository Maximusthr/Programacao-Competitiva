#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y; cin >> x >> y;

    map<string, string> mapa;

    for (int i = 0; i < y; i++){
        string a, b; cin >> a >> b;
        if (a.size() <= b.size()) {
            mapa[b] = a;
            mapa[a] = a;
        }
        else {
            mapa[a] = b;
            mapa[b] = b;
        }
    }

    for (int i = 0; i < x; i++){
        string aux; cin >> aux;
        cout << mapa[aux] << " ";
    }

    cout << "\n";
}
