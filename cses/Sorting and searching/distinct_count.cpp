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
    
    int count = 0;
    for (int i = 0; i < MAX; i++){
        if (lista[i]) count++;
    }

    cout << count << "\n";
}
