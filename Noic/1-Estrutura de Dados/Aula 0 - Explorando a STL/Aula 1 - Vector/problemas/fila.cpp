#include <bits/stdc++.h>

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
            if (y == fila[i]) fila[i] = -1;
        }
    }

    for (int i = 0; i < (int)fila.size(); i++){
        if (fila[i] == -1){
            continue;
        }
        cout << fila[i] << " ";
    }
    cout << "\n";
}
