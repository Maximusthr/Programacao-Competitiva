#include <iostream>

using namespace std;

const int MAX = 102;
int lista[MAX];

int main(){
    int n, m;
    cin >> n >> m;

    int i, j, k = 0, count = 0, aux = 0;
    int x;

    for (i = 0; i < m; i++){
        cin >> x;
        for (j = 0; j < m; j++){
            if (x == lista[j]) {
                aux++;
                break;
            }
        }
        if (aux > 0) aux = 0;
        else {
            lista[k] = x;
            k++;
            count++;
        }
    }

    cout << n - count << "\n";
}
