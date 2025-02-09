#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        long long area = x * y;
        long long soma = 2147483647;
        long long aux = 0;

        if (y == 1){
            for (int i = 0; i <= a; i++){
                for (int j = 0; j < y; j++){
                    aux++;
                }
            }
            if (aux < soma) soma = aux;

            aux = 0;
            for (int i = a; i < x; i++){
                for (int j = 0; j < y; j++){
                    aux++;
                }
            }
            if (aux < soma) soma = aux;
        }
        else {
            // primeiro caso i < x e j <= b
            for (int i = 0; i < x; i++){
                for (int j = 0; j <= b; j++){
                    aux++;
                }
            }
            if (aux < soma) soma = aux;
            
            // segundo caso i < x e j = b e j < y
            aux = 0;
            for (int i = 0; i < x; i++){
                for (int j = b; j < y; j++){
                    aux++;
                }
            }
            if (aux < soma) soma = aux;

            // terceiro caso i < b e j < y
            if (b > 0 && b < x){
                aux = 0;
                for (int i = 0; i < b; i++){
                    for (int j = 0; j < y; j++){
                        aux++;
                    }
                }
                if (aux < soma) soma = aux;
            }

            //quarto caso i = b; i < x e j < y;
            if (x > b){
                aux = 0;
                for (int i = b; i < x; i++){
                    for (int j = 0; j < y; j++){
                        aux++;
                    }
                }
                if (aux < soma) soma = aux;
            }
        }

        cout << area-soma << "\n";
    }
}
