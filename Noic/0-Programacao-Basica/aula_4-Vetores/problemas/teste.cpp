#include <iostream>

using namespace std;

const int MAX = 201;
int lista[MAX];

int main(){
    int n, m; // n pedra, m sapos.
    cin >> n >> m;

    int i, j;
    for (i = 1; i <= m; i++){
        int p, d; // p -> pedra inicial e d -> distancia
        cin >> p >> d;
        lista[p] = 1;
        int aux = d, incremento = d;
        for (j = 1; j <= n; j++){
            if (p + d <= n) lista[p+d] = 1;
            else if (p - aux > 0) {
                lista[p-aux] = 1;
                aux += incremento;
            } else break;
            d += incremento;
        }
    }

    for (i = 1; i <= n; i++){
        cout << lista[i] << "\n";
    }
}