// tentativa O(n²) -> time limit error
#include <bits/stdc++.h>

using namespace std;

const int MAX = 50001;

vector<int> aux(MAX);

int main(){
    int n; cin >> n;
    vector<int> lista;

    while (n--){
        int x; cin >> x;
        aux[x] = 1;
        lista.push_back(x);
    }

    cin >> n;
    while (n--){
        int y; cin >> y;
        aux[y] = 0;
    }
    int i;
    for (i = 0; i < (int)lista.size(); i++){
        if (aux[lista[i]]) cout << lista[i] << " ";
    }

    cout << "\n";
}