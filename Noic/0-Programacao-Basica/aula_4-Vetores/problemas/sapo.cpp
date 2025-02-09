#include <iostream>

using namespace std;

const int MAX = 201;
int lista[MAX];

int main(){
    int n, m;
    cin >> n >> m;
    int i, j;
    for (i = 1; i <= m; i++){
        int p, d;
        cin >> p >> d;
        lista[p] = 1;
        int aux_dist = d, aux = d;
        while(p+d <= n){
            lista[p+d] = 1;
            d += aux;
        }
        while (p - aux_dist > 0){
            lista[p-aux_dist] = 1;
            aux_dist += aux;
        }
    }
    
    for (i = 1; i <= n; i++){
        cout << lista[i] << "\n";
    }
}
