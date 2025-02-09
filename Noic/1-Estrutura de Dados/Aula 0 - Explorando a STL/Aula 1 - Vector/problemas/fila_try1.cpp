// tentativa O(n²) -> time limit error

#include <bits/stdc++.h> // importa todas as bibliotecas
#include <algorithm> // sort
#include <vector> // vector

using namespace std;

int main(){
    vector<int> fila;

    int n; cin >> n;
    while (n--){
        int x; cin >> x;
        fila.push_back(x);
    }
    cin >> n;
    while (n--){
        int y; cin >> y;
        for (int i = 0; i < (int)fila.size(); i++){
            if (y == fila[i]) fila.erase(fila.begin()+i);
        }
    }

    for (int i = 0; i < (int)fila.size(); i++){
        cout << fila[i] << " ";
    }
    cout << "\n";

}
