#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 1e9+1;
bitset<MAX> lista;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        lista[x] = 1;
    }
    
    cout << lista.count() << "\n";
}
